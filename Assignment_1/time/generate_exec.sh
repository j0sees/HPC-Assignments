#!/bin/bash
# Generates the executables with all the optimization levels

CFLAGS='O0 O1 O2 O3 Os Og'
for FLAG in $CFLAGS; do
	gcc -$FLAG -o naiveSum_$FLAG $1
done

exit 0
