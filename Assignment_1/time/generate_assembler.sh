#!/bin/bash
# Generates the assembler code for all the optimization levels

CFLAGS='O0 O1 O2 O3 Os Og'
for FLAG in $CFLAGS; do
	gcc -S -$FLAG -o naiveSum_$FLAG.s $1
done

exit 0
