#!/bin/bash

COBJ='testsum3 testsum2 testsum1 testsum0 testsums testsumg'
for FILE in $COBJ; do
	COUNTER=0
	AVGTIME=0
	while [ $COUNTER -lt 1000 ]; do
		START=`date +%s.%N`
		./$FILE
		END=`date +%s.%N`
		DIFF=`echo $END - $START | bc -l`
		AVGTIME=`echo $AVGTIME + $DIFF | bc -l`
		let COUNTER+=1
	done
	AVGTIME=`echo $AVGTIME/100 | bc -l`
	echo Average time for $FILE: $AVGTIME >> timestamps.txt
done

exit 0
