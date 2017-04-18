# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-T934

CC = gcc
COBJ = indirect_O0 indirect_O3 direct_O0 direct_O3 

.PHONY : all time clean

all : $(COBJ) time

indirect_O0 : indirect_addressing.o
	$(CC) -O0 -o indirect_O0 indirect_addressing.o

indirect_O3 : indirect_addressing.o 
	$(CC) -O3 -o indirect_O3 indirect_addressing.o

indirect_addressing.o : indirect_addressing.c bogus.h
	$(CC) -c indirect_addressing.c

direct_O0 : direct_addressing.o
	$(CC) -O0 -o direct_O0 direct_addressing.o

direct_O3 : direct_addressing.o 
	$(CC) -O3 -o direct_O3 direct_addressing.o

direct_addressing.o : direct_addressing.c bogus.h
	$(CC) -c direct_addressing.c

time : $(COBJ) 
	./timing.sh $(COBJ)

clean :
	rm indirect_O* direct_O* indirect_addressing.o direct_addressing.o timestamps.txt
