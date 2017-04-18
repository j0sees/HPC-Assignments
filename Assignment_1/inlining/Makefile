# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-T934

CC = gcc

.PHONY : all clean time

all : inlining inlining.o time

inlining : inlining.o
	$(CC) -o inlining inlining.o

inlining.o : inlining.c bogus.h mul_cpx.h
	$(CC) -c inlining.c

time : inlining
	./timing.sh inlining

clean : 
	rm inlining.o inlining timestamps.txt
