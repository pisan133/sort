#!/bin/bash

# To more easily compile and run this program on CSS Linux Lab
# Lines starting with '$' indicate what is typed on command line

# if you get the following error:
# -bash: ./simplecompile.sh: /bin/bash^M: bad interpreter: No such file or directory
# run dos2unix to fix it
# $ dos2unix simplecompile.sh

# make this file executable
# $ chmod 700 simplecompile.sh
# redirect the output and stderr from this file to output.txt
# $ ./simplecompile.sh > output.txt 2>&1


date

echo "*** Compiling"
CMD="clang++ -std=c++14 -Wall -Wextra -Wno-sign-compare *.cpp -g -o myprogram.exe"
echo $CMD
$CMD

echo "*** running"
CMD="./myprogram.exe"
echo $CMD
$CMD

echo "*** cleaning up"
CMD="rm myprogram.exe"
echo $CMD
$CMD

date

