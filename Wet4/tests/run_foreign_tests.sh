#!/bin/bash
#
####################################################################################################
# C Shai Yehezkel
#
# Script      :  run_foreign_tests.sh
# Version     :  1
# Arguements  :  prog1,prog2 [2]
# Description :  NONE
#
#
#
####################################################################################################


#Variables defenitions
TESTS_DIR="../adjusted_tests_hw4"
cd $TESTS_DIR
rm a.out
for f in * # Loop over all test files
do
	base="$(basename -- $f)"	
	echo "************** $base start ***************************"
	echo ""
	echo "Compiling $base"
	`g++ $base`
	echo "Running $base"
	./a.out
	
	echo ""
	echo "************** $base end ***************************"
	
done
rm a.out