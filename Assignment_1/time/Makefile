# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-T934

CC = gcc

COBJ = naiveSum_O0 naiveSum_O1 naiveSum_O2 naiveSum_O3 naiveSum_Os naiveSum_Og

.PHONY : all time clean

all : assembler execs time

execs : time.c
	./generate_exec.sh time.c

assembler : time.c
	./generate_assembler.sh time.c

time : $(COBJ)
	./timing.sh $(COBJ)

clean : 
	rm naiveSum_O* timestamps.txt
