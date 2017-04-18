# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-T934

CC = gcc
COBJ = locality_gprof locality_gcov

.PHONY : all gprof gcov time clean 

all : locality_gprof locality_gcov gprof gcov

time : $(COBJ)
	./timing.sh $(COBJ)

locality_gprof : locality.c bogus.h
	$(CC) -w -pg -o locality_gprof locality.c
	./locality_gprof

gprof : locality_gprof
	gprof locality_gprof gmon.out > analysis.txt

locality_gcov : locality.c bogus.h
	$(CC) -w --coverage locality.c -o locality_gcov
	./locality_gcov

gcov : locality_gcov
	gcov -abcf locality.c

clean :
	rm locality_gprof locality_gcov *.gcda *.gcno *.gcov analysis.txt gmon.out timestamps.txt
