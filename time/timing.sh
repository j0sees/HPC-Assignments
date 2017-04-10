#!/bin/bash

COBJ='naiveSum_O0 naiveSum_O1 naiveSum_O2 naiveSum_O3 naiveSum_Os naiveSum_Og'
IT=1000
for FILE in $COBJ; do
	COUNTER=0
	AVGTIME=0
	while [ $COUNTER -lt $IT ]; do
		START=`date +%s.%N`
		./$FILE
		END=`date +%s.%N`
		DIFF=`echo $END - $START | bc -l`
		AVGTIME=`echo $AVGTIME + $DIFF | bc -l`
		let COUNTER+=1
	done
	AVGTIME=`echo $AVGTIME/$IT | bc -l`
	echo Average time for $FILE: $AVGTIME >> timestamps.txt
done

exit 0
