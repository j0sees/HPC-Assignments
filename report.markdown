# HPC: Assignment 1: Optimization

## Time

opotimization levels	| average time over 1000 runs in secounds
-----------------------------------------------------------------
O0			| 3.26337337146600000000
O1			| 0.37415721621400000000
O2			| 0.00125840047300000000
O3			| 0.00123499591100000000
Os			| 0.00124891658400000000
Og			| 0.37296328826700000000


## Inlining

 * The average time over 10000 runs with inlining is 0.00243623078750000000 secounds.
 * The average time over 10000 runs without inlining is 0.00235497980470000000 secounds.
 
The solution surprises us, as we expected that inlining would increase the performance of our program.
We expected that the program would ran faster with inlining than without. 
As the program does not have to resolve the call of the method "mul_cpx()" from a different file.
We came up with two possible explanations for this behaviour.
 1. We did not use any optimization flags like -O1 or O3. 
 2. Maybe inlining the code by hand, is not as effective as for example
    inlining the code by calling "inline type function(type a, type b);".
    Which gives the compiler a hint that it should optimize this code.
 
## Locality

program name			| average time over 10000 runs in secounds
-------------------------------------------------------------------------
locality: O0			| 0.01488468323600000000
locality: O3			| 0.01562584573200000000
locality Reimplemented sum: O0	| 0.01780300799200000000
locality Reimplemented sum: O3	| 0.01630556445600000000

We reimplemented the functions "row_sums" and "col_sums" as a function "sumsRowCol".
By doing this we eliminated a for loop and a function call. 
We expected an improvement of our runtime.

## Indirect addressing

## Valgrind 

## Profiling
