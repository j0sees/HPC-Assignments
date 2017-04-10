Link usage of the markup file in GitHub: 
[https://github.com/tchapi/markdown-cheatsheet/blob/master/README.md]

# HPC: Assignment 1: Optimization
## Time
### Code [11] D:
### Testing [8] E:
### Report [0] D,E:

## Inlining 06.04.2017
### Code [11] D:
This is done!
### Testing [0] E:
### Report [0] D,E:

## Locality
### Code [11] D:
### Testing [8] E:
* Makefile done!

!!! The program has to be  run with and without full optimization. I only can find one entry in the timestamp shouldn't there be two? !!!

### Report [0] D,E:

## Indirect addressing -->  05.04.2017 D
### Code [10] D: 
* Part I (using indirect addressing):
	* Is done!
	* Currently with dummy data but printf is commented out.
* Part II (without indirect addressing):
	* Is done!
### Testing [0] E:
### Report [0] D,E:

## Valgrind
### Code [10] D:
* How to call the programm:
	* I compiled leak once in a folder leak_O0 and in a folder leak_O1.
	1. leak is locality modified with the method/function "thousandUnFreeIntegers()" 
	2. Makefile which includes --> valgrind --leak-check=yes leak

Helpfull link:
* Valgrind manual: 
	* [http://valgrind.org/docs/manual/quick-start.html]
	* [http://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks]
	* Compile the program with -g and -O0 or -O1 NOT higher!
	1. To run the program we use: "valgrind --leak-check=yes myprog arg1 arg2" instead of ./myprog
	* THIS IS UR TASK ESTEBAN!
	
### Testing [0] E:
### Report [0] D,E:

## Profiling 05.04.2017 E
### Code [10] E:
* Clean the code a bit
### Testing [8] E:
* Makefile done!
* Discuss results
### Report [0] D,E:
