#!/bin/bash

COBJ=$@
IT=10000
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
	echo Average time for $FILE with inlining: $AVGTIME >> timestamps.txt

done

exit 0
