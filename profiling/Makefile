# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-T934

CC = gcc
COBJ = locality_reimpsum

all : locality_reimpsum

.PHONY : all gprof gcov time clean 

time : $(COBJ)
	./timing.sh $(COBJ)

locality_reimpsum_gprof : locality_reimpsum.c
	$(CC) -w -pg -o locality_reimpSum locality_reimpSum.c

locality_reimpsum_gcov : locality_reimpsum.c
	$(CC) -w -fprofile-arcs -ftest-coverage locality_reimpsum.c -o locality_reimpsum
	./locality_reimpsum

gprof : locality_reimpsum
	$(CC) -w -pg -o reimpSum HPC_A1_Task03_Locality_ReimpSum_data.c
	./reimpSum
	gprof locality_reimpsum gmon.out > analysis.txt
	rm reimpSum

gcov :
	$(CC) -w -fprofile-arcs -ftest-coverage locality_reimpsum.c -o reimpSum
	./reimpSum
	gcov -b HPC_A1_Task03_Locality_ReimpSum_data.c
	rm reimpSum
