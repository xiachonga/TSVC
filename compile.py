import os
import subprocess


gem5 = "../gem5"
loops = []


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


def get_flags(llvm, vec, sve):
    gem5_includes = os.path.join(gem5, "include")
    gem5_libs = os.path.join(gem5, "util/m5/build/arm64/out")
    if not os.path.exists(os.path.join(gem5_includes, "gem5/m5ops.h")):
        print("File gem5/m5ops.h not exists in {}".format(gem5_includes))
        exit(-1)
    elif not os.path.exists(os.path.join(gem5_libs, "libm5.a")):
        print("File libm5.a not exists in {}".format(gem5_libs))
        exit(-1)
    flags = []
    # common flags
    flags.append("-std=c99")
    flags.append("-w")
    flags.append("-I" + gem5_includes)
    flags.append("-O3")
    flags.append("-funsafe-math-optimizations")
    if vec:
        if llvm:
            flags.append("-Rpass=loop")
            flags.append("-Rpass-analysis=loop")
        else:
            flags.append("-fopt-info-vec")
    else:
        flags.append("-fno-tree-vectorize")
    # target triple flags
    if llvm:
        flags.append("--target=aarch64-linux-gnu")
    if sve:
        flags.append("-march=armv8.2-a+sve")
        if llvm:
            flags.append("-mllvm")
            flags.append("-scalable-vectorization=preferred")
    else:
        flags.append("-march=armv8.2-a")
    # link flags
    link_flags = []
    if llvm:
        link_flags.append("-fuse-ld=lld")
        link_flags.append("--target=aarch64-linux-gnu")
    link_flags.append("-O0")
    link_flags.append("-static")
    link_flags.append("-L" + gem5_libs)
    return flags, link_flags


def get_vec_info(outputs, llvm, vec, sve):
    vec_loops = []
    sve_loops = []
    neon_loops = []
    if not vec:
        return vec_loops, sve_loops, neon_loops
    for loop, output in zip(loops, outputs):
        if llvm:
            if "vectorization width" in output:
                vec_loops.append(loop)
                if "vectorization width: vscale" in output:
                    sve_loops.append(loop)
                if "vectorization width: 4" in output:
                    neon_loops.append(loop)
                if "vectorization width: 2" in output:
                    neon_loops.append(loop)
        else:
            if "vectorized" in output:
                vec_loops.append(loop)
                if "variable length vectors" in output:
                    sve_loops.append(loop)
                if "byte vectors" in output:
                    neon_loops.append(loop)
    print("Total loops:           {0:3d}".format(len(loops)))
    print("Vectorized loops:      {0:3d}".format(len(vec_loops)))
    if sve:
        print("SVE vectorized loops:  {0:3d}".format(len(sve_loops)))
        print("Neon vectorized loops: {0:3d}".format(len(neon_loops)))
    return vec_loops, sve_loops, neon_loops


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


def compile(CC, llvm=True, vec=True, sve=True, exe=True):
    # compile all loops
    flags, link_flags = get_flags(llvm, vec, sve)
    outputs = []
    for loop in loops:
        file = os.path.join("./loops", loop + ".c")
        outputs.append(compile_one(CC, flags, file, exe))
    # get vectorization info
    vec_loops, sve_loops, neon_loops = get_vec_info(outputs, llvm, vec, sve)
    if exe:
        main_loops = loops
        if vec:
            main_loops = sve_loops if sve else vec_loops
        delete_unvec_loops(main_loops)
        compile_one(CC, flags, "./main.2.c")
        compile_one(CC, flags, "./dummy.c")
        # generate executable file
        cmd = [CC]
        cmd.extend(link_flags)
        cmd.append("-o")
        outfile = "llvm-" if llvm else "gcc-"
        outfile += ("sve" if sve else "neon") if vec else "scalar"
        outfile += ".out"
        cmd.append(outfile)
        ofiles = [os.path.join("./loops", loop + ".o") for loop in main_loops]
        ofiles.append("./dummy.o")
        ofiles.append("./main.2.o")
        cmd.extend(ofiles)
        cmd.append("-lm")
        cmd.append("-lm5")
        run_cmd(cmd)
    return vec_loops, sve_loops, neon_loops


if __name__ == "__main__":
    if not os.path.exists("./loops"):
        from generate_loops import generate_loops, process_one_loop
        generate_loops(process_one_loop)
    for _, _, files in os.walk("./loops"):
        loops = [loop[0:-2] for loop in files if loop[-1] == "c"]
    loops.sort()
    CC = "aarch64-linux-gnu-gcc"
    run_cmd([CC, "--version"])
    print("# aarch64 gcc scalar")
    compile(CC, llvm=False, vec=False, sve=False)
    print("# aarch64 gcc neon:")
    gcc_neon_loops, _, _ = compile(CC, llvm=False, sve=False)
    print("# aarch64 gcc sve:")
    _, gcc_sve_loops, _ = compile(CC, llvm=False)
    # llvm-project/llvm/lib/Transforms/Vectorize/LoopVectorize.cpp:5995
    # return true;
    # // return (CostA * B.Width.getKnownMinValue()) <
    #           (CostB * A.Width.getKnownMinValue())
    CC = "clang"
    run_cmd([CC, "--version"])
    print("# aarch64 llvm scalar")
    compile(CC, vec=False, sve=False)
    print("# aarch64 llvm neon:")
    llvm_neon_loops, _, _ = compile(CC, sve=False)
    print("# aarch64 llvm sve:")
    _, llvm_sve_loops, _ = compile(CC)
    print("\tGCC\t\tLLVM")
    print("Loop\tNEON\tSVE\tNEON\tSVE")
    for loop in loops:
        print("{}\t{}\t{}\t{}\t{}".format(
            loop,
            loop in gcc_neon_loops, loop in gcc_sve_loops,
            loop in llvm_neon_loops, loop in llvm_sve_loops))
    # aarch64-linux-gcc 11.2.0
    # clang 13.0.1
    # 151 68 79 65 89
    print("{}\t{}\t{}\t{}\t{}".format(
        len(loops), len(gcc_neon_loops), len(gcc_sve_loops),
        len(llvm_neon_loops), len(llvm_sve_loops)))

