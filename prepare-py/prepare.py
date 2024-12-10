import os
import shutil
from typing import Mapping, Any
from pathlib import Path
from string import Template

MAKEFILE_TEMPLATE = Template("""\
include ../Makefile.config

${day}_1 : ${day}_1.cpp ${day}_commons.cpp
\t$${COMPILER} $${COMPILER_OPTS} -o ${day}_1.tsk ${day}_1.cpp ${day}_commons.cpp

${day}_2 : ${day}_2.cpp ${day}_commons.cpp
\t$${COMPILER} $${COMPILER_OPTS} -o ${day}_2.tsk ${day}_2.cpp ${day}_commons.cpp
""")

CPP_TEMPLATE = Template("""\
#include "${day}_commons.h"

using namespace std;

int main() {

    return 0;
}
""")

COMMONS_TEMPLATE = Template("""\
#include "${day}_commons.h"
""")

COMMONS_HEADER_TEMPLATE = Template("""\
#ifndef COMMONS${day}_H
#define COMMONS${day}_H

#include <bits/stdc++.h>
using namespace std;

#endif // COMMONS${day}_H
""")

FOLDER_STRUCTURE: Mapping[Template, Mapping[Template, Any]] = {
    Template("Day ${day}"): {
        Template("Makefile"): MAKEFILE_TEMPLATE,
        Template("${day}_1.cpp"): CPP_TEMPLATE,
        Template("${day}_2.cpp"): CPP_TEMPLATE,
        Template("${day}_commons.cpp"): COMMONS_TEMPLATE,
        Template("${day}_commons.h"): COMMONS_HEADER_TEMPLATE,
        Template("${day}_input.txt"): Template(""),
    }
}


def _prepare_files_recursive(
    cwd: Path, structure: Mapping[Template, Template | Mapping], day: int
) -> None:
    for name_template, content_obj in structure.items():
        name = name_template.substitute(day=day)
        if isinstance(content_obj, Template):
            with open(cwd / name, "w") as f:
                f.write(content_obj.substitute(day=day))
        else:
            new_cwd = cwd / name
            new_cwd.mkdir()
            _prepare_files_recursive(new_cwd, content_obj, day)


def clear_dir(root: Path) -> None:
    for child in root.iterdir():
        if child.is_dir() and child.name.startswith("Day "):
            shutil.rmtree(child)


def prepare_files(root: Path, day: int) -> None:
    _prepare_files_recursive(root, FOLDER_STRUCTURE, day)


if __name__ == "__main__":
    cwd = Path(os.getcwd())
    clear_dir(cwd)
    for day in range(1, 26):
        prepare_files(cwd, day)
