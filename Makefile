# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-T934

CC = gcc
CFLAGS = O0 O1 O2 O3 Os Og 
COBJ = testsum0 testsum1 testsum2 testsum3 testsums testsumg

all : $(COBJ) time 

time : $(COBJ)
	./script.sh

testsum0 : HPC_A1_Task01_Time.c
	$(CC) -O0 -o testsum0 HPC_A1_Task01_Time.c

testsum1 : HPC_A1_Task01_Time.c
	$(CC) -O1 -o testsum1 HPC_A1_Task01_Time.c

testsum2 : HPC_A1_Task01_Time.c
	$(CC) -O2 -o testsum2 HPC_A1_Task01_Time.c

testsum3 : HPC_A1_Task01_Time.c
	$(CC) -O3 -o testsum3 HPC_A1_Task01_Time.c

testsums : HPC_A1_Task01_Time.c
	$(CC) -Os -o testsums HPC_A1_Task01_Time.c

testsumg : HPC_A1_Task01_Time.c
	$(CC) -Og -o testsumg HPC_A1_Task01_Time.c
