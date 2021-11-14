from compile import get_vec_info
import re
import os


def split_loop_function(lines):
    init = []
    body = []
    dummy = None
    check = []
    i = 0
    for line in lines[i:]:
        i = i + 1
        if "ntimes" in line:
            break
        if "start_t" not in line and "end_t" not in line:
            init.append(line)
    for line in lines[i:]:
        i = i + 1
        if "dummy(" in line:
            dummy = line
            break
        body.append(line)
    for line in lines[i:]:
        i = i + 1
        if "}" in line:
            break 
    for line in lines[i:]:
        if "end_t" in line or "clock_dif" in line or "printf" in line:
            continue
        check.append(line)
    return init, body, dummy, check


def process_one_loop(loop, lines):
    init, body, dummy, check = split_loop_function(lines)
    lines = init
    lines.append("\tint64_t start_t[2], end_t[2];\n")
    lines.append("\tfor(int i = 0; i < 2; i++) {\n")
    lines.append("\t\tstart_t[i] = m5_rpns();\n")
    lines.extend(body)
    lines.append(dummy)
    lines.append("\t\tend_t[i] = m5_rpns();\n")
    lines.append("\t}\n")
    lines.append("\t" + r'printf("{}\t %8ld   %8ld   ", end_t[0] - start_t[0], end_t[1] - start_t[1]);'.format(loop) + "\n")
    lines.extend(check)
    return lines


def generate_loops(process_one_loop=None):
    # get loop functions from tsc.c
    with open("./tsc.c", "r") as tsc:
        lines = tsc.readlines()
    loops = []
    functions = {}
    function = None
    for line in lines:
        if function is None:
            if re.match(r"int (v.*|s[0-9]*)\(.*\)", line):
                function = re.split("[ \(]", line)[1]
                loops.append(function)
            elif re.match(r"float test\(", line):
                function = re.split("[ \(]", line)[1]
            elif re.match(r"int [0-9s]*\(.*\)", line):
                function = re.split("[ \(]", line)[1]
            elif re.match(r"inline ", line):
                function = re.split("[ \(]", line)[2]
            if function is not None: 
                functions[function] = [line]
        else:
            functions[function].append(line)
            if "}" == line[0]:
                function = None
    # process loops
    if process_one_loop is not None:
        for loop in loops:
            functions[loop] = process_one_loop(loop, functions[loop])
            # break
    # write files
    special_loops = {
        "s151" : "s151s",
        "s152" : "s152s",
        "s31111" : "test",
        "s4121" : "f",
        "s471" : "s471s",
    }
    for loop in loops:
        if not os.path.exists("./loops"):
            os.mkdir("./loops")
        with open(os.path.join("./loops", loop + ".c"), "w") as lf:
            lf.write('#include "../common.h"\n\n')
            if loop in special_loops:
                lf.writelines(functions[special_loops[loop]])
                lf.write("\n")
            lf.writelines(functions[loop])



if __name__ == "__main__":
    generate_loops(process_one_loop)
