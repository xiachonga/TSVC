import os
import subprocess


def get_repetitions():
    repetitions = {}
    with open("./repetitions.txt", "r") as f:
        lines = f.readlines()
        for line in lines:
            items = line.split()
            repetitions[items[0]] = int(items[1])
    return repetitions


repetitions = get_repetitions()
loops = [loop for loop in repetitions.keys()]
loops.sort()


def gen_repetitions(time=32000):
    for i in range(3):
        for loop in loops:
            if i != 0:
                repetitions[loop] *= 10
            else:
                repetitions[loop] = 4
        compile("aarch64-none-linux-gnu-gcc", exe=True, vec=False)
        res = run_cmd(["./gcc-scalar.out"])
        lines = res.split("\n")
        avg = 0
        for line in lines:
            items = line.split()
            if len(items) != 4 or items[0].lower() not in loops:
                continue
            items[0] = items[0].lower()
            repetitions[items[0]] = max(1, int(time * int(items[1]) / max(1, int(items[2]))))
            avg += int(items[2])
        print("{}: avg time {}us".format(i, avg / len(loops)))
        with open("./repetitions.txt", "w") as f:
            for loop in loops:
                f.write("{}\t{}\n".format(loop, repetitions[loop]))
    print(res)
    return


def run_cmd(cmd):
    try:
        proc = subprocess.run(cmd, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, check=True)
        return proc.stdout
    except subprocess.CalledProcessError:
        print("Error:")
        print(" ".join(cmd))
        exit(-1)


def compile_one(CC, flags, file, object=True):
    cmd = [CC]
    cmd.extend(flags)
    if object:
        cmd.extend(["-c", "-o", file[0:file.rfind(".")] + ".o"])
    else:
        cmd.extend(["-S", "-o", file[0:file.rfind(".")] + ".s"])
    cmd.append(file)
    return run_cmd(cmd)


def get_gcc_flags(vec, sve, x64):
    flags = []
    # common flags
    flags.append("-std=c99")
    flags.append("-w")
    flags.append("-I./")
    # vectorize flags
    flags.append("-O3")
    flags.append("-funsafe-math-optimizations")
    if vec:
        flags.append("-fopt-info-vec")
    else:
        flags.append("-fno-tree-vectorize")
    # target triple flags
    if x64:
        flags.append("-march=native")
    elif sve:
        flags.append("-march=armv8.2-a+sve")
    else:
        flags.append("-march=armv8.2-a")
    # link flags
    link_flags = []
    link_flags.append("-O0")
    link_flags.append("-static")
    return flags, link_flags


def print_vec_info(vec_loops, sve_loops=None, neon_loops=None):
    print("Total loops:           {0:3d}".format(len(loops)))
    print("Vectorized loops:      {0:3d}".format(len(vec_loops)))
    if sve_loops is None or neon_loops is None:
        return
    if len(sve_loops) == 0:
        return
    print("SVE vectorized loops:  {0:3d}".format(len(sve_loops)))
    print("Neon vectorized loops: {0:3d}".format(len(neon_loops)))


def delete_unvec_loops(vec_loops):
    with open("./main.c", "r") as f:
        lines = f.readlines()
    with open("./main.2.c", "w") as f:
        main = False
        for line in lines:
            if not main:
                f.write(line)
                if "main" in line:
                    main = True
                continue
            items = line.split()
            if len(items) != 0:
                items = items[0].split("(")
                if items[0] in loops and items[0] not in vec_loops:
                    line = "// " + line
                elif items[0] == "s176":
                    line = "// " + line
            f.write(line)
    return


def compile(CC, info=True, gcc=True, vec=True, sve=True, exe=True, x64=False):
    # compile all loops
    if gcc:
        flags, link_flags = get_gcc_flags(vec, sve, x64)
    outputs = []
    flags.append("-DREPETITIONS=32")
    for loop in loops:
        flags[-1] = "-DREPETITIONS={}".format(repetitions[loop])
        file = os.path.join("./src", loop + ".c")
        outputs.append(compile_one(CC, flags, file, exe))
    # get vectorization info
    vec_loops = []
    sve_loops = []
    neon_loops = []
    for loop, output in zip(loops, outputs):
        if gcc:
            if "vectorized" in output:
                vec_loops.append(loop)
                if "variable length vectors" in output:
                    sve_loops.append(loop)
                if "byte vectors" in output:
                    neon_loops.append(loop)
        else:
            pass
    if info and vec:
        print_vec_info(vec_loops, sve_loops, neon_loops)
    if exe:
        if not vec:
            delete_unvec_loops(loops)
        elif x64 or not sve:
            delete_unvec_loops(vec_loops)
        else:
            delete_unvec_loops(sve_loops)
        compile_one(CC, flags, "./main.2.c")
        # generate executable file
        compile_one(CC, flags, "./dummy.c")
        cmd = [CC]
        cmd.extend(link_flags)
        cmd.append("-o")
        outfile = "gcc-" if gcc else "llvm-"
        if x64:
            outfile += "x64-vectorized" if vec else "x64-scalar"
        else:
            outfile += ("sve" if sve else "neon") if vec else "scalar"
        outfile += ".out"
        cmd.append(outfile)
        ofiles = []
        for root, _, files in os.walk("./src"):
            ofiles = [os.path.join(root, file) for file in files if file[-1] == "o"]
            ofiles.sort()
        ofiles.append("./dummy.o")
        ofiles.append("./main.2.o")
        cmd.extend(ofiles)
        cmd.append("-lm")
        run_cmd(cmd)
    return vec_loops, sve_loops, neon_loops


if __name__ == "__main__":
#    gen_repetitions()
    print("# aarch64 gcc scalar:")
    compile("aarch64-none-linux-gnu-gcc", vec=False, sve=False, exe=True)
    print("# aarch64 gcc neon:")
    compile("aarch64-none-linux-gnu-gcc", sve=False, exe=True)
    print("# aarch64 gcc sve:")
    compile("aarch64-none-linux-gnu-gcc", exe=True)
    
