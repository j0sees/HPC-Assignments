# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-T934

CC = gcc

all : locality locality_ReimpSum locality_O3 locality_ReimpSum_O3 clean

locality : HPC_A1_Task03_Locality.c
	$(CC) -w -O0 -o locality HPC_A1_Task03_Locality.c
	./timing.sh locality

locality_O3 : HPC_A1_Task03_Locality.c
	$(CC) -w -O3 -o locality_O3 HPC_A1_Task03_Locality.c
	./timing.sh locality_O3

locality_ReimpSum : HPC_A1_Task03_Locality_ReimpSum.c
	$(CC) -w -O0 -o locality_ReimpSum HPC_A1_Task03_Locality_ReimpSum.c
	./timing.sh locality_ReimpSum

locality_ReimpSum_O3 :  HPC_A1_Task03_Locality_ReimpSum.c
	$(CC) -w -O3 -o locality_ReimpSum_O3 HPC_A1_Task03_Locality_ReimpSum.c
	./timing.sh locality_ReimpSum_O3

clean :
	rm loc*
