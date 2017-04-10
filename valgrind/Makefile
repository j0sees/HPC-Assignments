# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-T934

CC = gcc

all : leak_O0 leak_O1

.PHONY : all clean check

leak_O0 : leak.c
	$(CC) -w -g -O0 -o leak_O0 leak.c

leak_O1 : leak.c
	$(CC) -w -g -O1 -o leak_O1 leak.c

check : leak_O0 leak_O1
	valgrind --leak-check=full --log-file="logfile_leak_O0.txt" -v ./leak_O0
	valgrind --leak-check=full --log-file="logfile_leak_O1.txt" -v ./leak_O1

clean : 
	rm leak_O0 leak_O1 logfile_leak_*.txt
