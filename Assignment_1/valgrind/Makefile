# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-T934

CC = gcc

.PHONY : all clean check

all : leak_O0 check

leak_O0 : leak.c
	$(CC) -w -g -O0 -o leak_O0 leak.c

check : leak_O0
	valgrind --tool=memcheck --log-file="logfile_leak_O0.txt" ./leak_O0

clean : 
	rm leak_O0 logfile_leak_*.txt
