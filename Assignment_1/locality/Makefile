# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-T934

CC = gcc
COBJ = locality_O0 locality_O3 locality_reimpsum_O3 locality_reimpsum_O0

.PHONY : all time clean

all : $(COBJ) locality.o locality_reimpsum.o time

locality_O0 : locality.o
	$(CC) -w -O0 -o locality_O0 locality.o

locality_O3 : locality.o
	$(CC) -w -O3 -o locality_O3 locality.o

locality.o : locality.c bogus.h
	$(CC) -c locality.c

locality_reimpsum_O0 : locality_reimpsum.o
	$(CC) -w -O0 -o locality_reimpsum_O0 locality_reimpsum.o

locality_reimpsum_O3 : locality_reimpsum.o
	$(CC) -w -O3 -o locality_reimpsum_O3 locality_reimpsum.o

locality_reimpsum.o : locality_reimpsum.c bogus.h
	$(CC) -c locality_reimpsum.c

time : $(COBJ)
	./timing.sh $(COBJ)

clean :
	rm locality_O* locality_reimpsum_O* locality.o locality_reimpsum.o timestamps.txt
