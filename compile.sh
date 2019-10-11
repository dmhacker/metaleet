#!/bin/bash

SCRIPT=$(readlink -f "$0")
SCRIPTDIR=$(dirname "$SCRIPT")
BUILDDIR=${SCRIPTDIR}/build

COMPILEARGS=""
idx=0
for arg 
do
    if [ $idx -ne 0 ]; then
        if [ $idx -eq 1 ]; then
            COMPILEARGS="-DARGUMENT_${idx}=${arg}"
        else
            COMPILEARGS="${COMPILEARGS} -DARGUMENT_${idx}=${arg}"
        fi
    fi
    idx=$((idx + 1))
done

echo "==========================================="
echo "Target problem is '$1'."
echo "Compilation arguments are '${COMPILEARGS}'."
echo "==========================================="

mkdir -p $BUILDDIR 
cd $BUILDDIR
cmake .. "-DPROBLEM='${COMPILEARGS}'"
make $1
