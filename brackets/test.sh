#!/bin/sh

PROC="brackets"

for i in $(seq 1 10); 
do
	INPUT_FILE=$i".input.txt"
	RES_FILE=$i".res"
	OUTPUT_FILE=$i".output.txt"
	cat Brackets_testcase/$INPUT_FILE | ./$PROC > $RES_FILE
	diff Brackets_testcase/$OUTPUT_FILE $RES_FILE
	DIFF=$?
	if [ $DIFF -ne 0 ]; then
		echo "test"$i" fail"
	else
		rm -f $RES_FILE
		echo "test"$i" succ"
	fi
done

