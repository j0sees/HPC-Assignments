# Esteban Perez-Hidalgo
# 880416-0631
# Dorian Valverde-Baspineiro
# 881010-XXXX

CC = gcc
CFLAGS = O0 O1 O2 O3 Os Og
COBJ = testsum0 testsum1 testsum2 testsum3 testsums testsumg

all : $(COBJ) time

time : $(COBJ)
        for FILE in $(COBJ); do
                COUNTER=0
                echo paso 2
                AVGTIME=0
                while [ $(COUNTER) -lt 100 ]; do
                        echo paso 3
                        START=$(date +%s.%N)
                        ./$(FILE)
                        END=$(date +%s.%N)
                        DIFF=$(echo "$(END) - $(START)" | bc -l)
                        let AVGTIME=AVGTIME+DIFF
                        let COUNTER+=1
                done
                echo paso 4
		let AVGTIME=`echo $(AVGTIME)/100 | bc -l`
                echo Average time for $(FILE): $(AVGTIME)
        done

testsum0 : testsum.c
        $(CC) -O0 -o testsum0 testsum.c

testsum1 : testsum.c
        $(CC) -O1 -o testsum1 testsum.c

testsum2 : testsum.c
        $(CC) -O2 -o testsum2 testsum.c

testsum3 : testsum.c
        $(CC) -O3 -o testsum3 testsum.c

testsums : testsum.c
        $(CC) -Os -o testsums testsum.c

testsumg : testsum.c
        $(CC) -Og -o testsumg testsum.c

