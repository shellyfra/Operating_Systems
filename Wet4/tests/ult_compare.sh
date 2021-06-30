#!/bin/bash
#
####################################################################################################
# C Shai Yehezkel
#
# Script      :  ult_compare.sh
# Version     :  3
# Arguements  :  prog1,prog2 [2]
# Description :  Compares two programs with given test in the directory this script is executed.
#				 Also checks for memory leakage in each test, and informs the user whic program
#                Was more consuming memory-wise.
#
# Sub-scripts :  Valgrind
#
#
####################################################################################################


#Variables defenitions
LOG_NAME="ult_compare.log"
SEARCH_WORD="bytes allocated"
VALGRIND_LOG="valgrind.log"
VALGRIND="valgrind --log-file=$VALGRIND_LOG --error-exitcode=1 --leak-check=yes --track-origins=yes "
FILES=./test*.cpp
prog1_mem_favor=0
prog2_mem_favor=0

echo "Building reference tests"
rm -rf ref_tests
mkdir ref_tests
cp test*.cpp ref_tests/
cp aux_macro.h ref_tests/
cd ref_tests
for f in $FILES # Loop over all test files
do
	
	base="$(basename -- $f)"	
 	test_num=`(echo ${base} | cut -d'.' -f 1 | cut -d't' -f 3)`
	 echo "******** Test $test_num **********"
	echo "Building ref test $base"
	`g++ -o test${test_num}_ref test${test_num}.cpp`
	cd ../
	echo "Building program test $base"
	`g++ -o test${test_num} test${test_num}.cpp`

	log_prog_1="ref_test$test_num.out"
  log_prog_2="prog_test$test_num.out"
  cmd_line_args=`realpath $f`  
  	echo "Running test $base"
  ./ref_tests/test${test_num}_ref >$log_prog_1

	./test${test_num} >$log_prog_2		
	DIFF=`diff ref_test$test_num.out prog_test$test_num.out`
	if [ "$DIFF" != "" ] 
		then
			echo "Test $test_num : Different outputs! see $LOG_NAME"
			echo "Test $test_num : Different outputs!" >> $LOG_NAME
			read -p "Press enter to continue"
			#read varname
	fi
	if [ "$DIFF" == "" ] 
		then
			
			rm $log_prog_1
			rm $log_prog_2
	fi

	rm "test${test_num}"
	cd ref_tests
	
	rm "test${test_num}_ref"
	rm "test${test_num}.cpp"
done
if [ -f $LOG_NAME ]; then
	echo ""
    echo "Errors starts here!"
    echo ""
    cat $LOG_NAME	
    echo ""
    echo "Errors ends here!"
    exit -2
else
	rm -rf ref_tests
	rm test?
fi

exit 0
