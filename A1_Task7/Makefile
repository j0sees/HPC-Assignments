# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-T934

CC = gcc
#CFLAGS =  
#COBJ = 

all : gprof gcov

#time : $(COBJ)
#	./timing.sh

gprof : HPC_A1_Task03_Locality_ReimpSum_data.c
	$(CC) -w -pg -o reimpSum HPC_A1_Task03_Locality_ReimpSum_data.c
	./reimpSum
	gprof reimpSum gmon.out > analysis.txt
	rm reimpSum

gcov : HPC_A1_Task03_Locality_ReimpSum_data.c
	$(CC) -w -fprofile-arcs -ftest-coverage HPC_A1_Task03_Locality_ReimpSum_data.c -o reimpSum
	./reimpSum
	gcov -b HPC_A1_Task03_Locality_ReimpSum_data.c
	rm reimpSum
