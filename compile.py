import os
import subprocess


def run_cmd(cmd):
    try:
        proc = subprocess.run(cmd, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, check=True)
        return proc.stdout
    except subprocess.CalledProcessError:
        print("Error:")
        print(" ".join(cmd))
        exit(-1)
    pass


def compile(CC, flags, file, object=True):
    cmd = [CC]
    cmd.extend(flags)
    if object:
        cmd.extend(["-c", "-o", file[0:file.rfind(".")] + ".o"])
    else:
        cmd.extend(["-S", "-o", file[0:file.rfind(".")] + ".s"])
    cmd.append(file)
    return run_cmd(cmd)


def test(CC, gcc=True, vec=True, sve=True, exe=False, x64=False):
    if x64:
        sve = False
    flags = []
    # common flags
    flags.append("-std=c99")
    flags.append("-w")
    flags.append("-I./")
    # vectorize flags
    flags.append("-O3")
    flags.append("-funsafe-math-optimizations")
    if not vec:
        flags.append("-fno-tree-vectorize")
    if gcc:
        flags.append("-fopt-info-vec")
    # sve flags
    if x64:
        flags.append("-march=native")
    elif sve:
        flags.append("-march=armv8.2-a+sve")
    else:
        flags.append("-march=armv8.2-a")
    
    cfiles = []
    for root, _, files in os.walk("./src"):
        cfiles = [os.path.join(root, file) for file in files if file[-1] == "c"]
        cfiles.sort()

    vec_list = []
    sve_list = []
    neon_list = []
    for file in cfiles:
        res = compile(CC, flags, file, exe)
        if gcc:
            if "vectorized" in res:
                vec_list.append(file)
                if "variable length vectors" in res:
                    sve_list.append(file)
                if "byte vectors" in res:
                    neon_list.append(file)
        else:
            pass
    print("Total loops:           {0:3d}".format(len(cfiles)))
    print("Vectorized loops:      {0:3d}".format(len(vec_list)))
    if sve:
        print("SVE vectorized loops:  {0:3d}".format(len(sve_list)))
        print("Neon vectorized loops: {0:3d}".format(len(neon_list)))

    if not exe:
        return cfiles, vec_list, sve_list, neon_list

    # flags.append("-fno-tree-vectorize")
    compile(CC, flags, "./dummy.c")
    compile(CC, flags, "./main.c")
    # link
    flags = []
    flags.append("-O0")
    flags.append("-static")
    cmd = [CC]
    cmd.extend(flags)
    cmd.append("-o")
    outfile = "gcc-" if gcc else "llvm-"
    if not x64:
        outfile += "scalar" if not vec else "sve" if sve else "neon"
    else:
        outfile += "x64" if not vec else "x64-vec"
    outfile += ".out"
    cmd.append(outfile)

    ofiles = []
    for root, _, files in os.walk("./src"):
        ofiles = [os.path.join(root, file) for file in files if file[-1] == "o"]
        ofiles.sort()
    ofiles.append("./dummy.o")
    ofiles.append("./main.o")
    cmd.extend(ofiles)
    cmd.append("-lm")
    run_cmd(cmd)
    return cfiles, vec_list, sve_list, neon_list


if __name__ == "__main__":
    print("# x64 gcc:")
    test("gcc", exe=True, x64=True)
    print("# aarch64 gcc neon:")
    test("aarch64-none-linux-gnu-gcc", sve=False, exe=True)
    print("# aarch64 gcc sve:")
    test("aarch64-none-linux-gnu-gcc", exe=True)

