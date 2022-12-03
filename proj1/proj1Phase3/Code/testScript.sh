rows1=$((2 + $RANDOM % 5))
cols1=$((2 + $RANDOM % 5))
rows2=$cols1
cols2=$((2 + $RANDOM % 5))
bitToFlip=$((1 + $RANDOM % 31))
corRow=$((1 + $RANDOM % ($rows1 - 1)))
corCol=$((1 + $RANDOM % ($cols2 - 1)))
lower1=$((1 + $RANDOM % 6))
upper1=$((($lower1 + 1) + $RANDOM % 15))
lower2=$((1 + $RANDOM % 6))
upper2=$((($lower2 + 1) + $RANDOM % 15))

check_for_errors () {
    test=$1

    if [ $test -gt 0 ] 
    then 
        # MAIN
        if [ $test -eq 83 ]
        then
            echo "The matrices provided cannot be multiplied!"
            exit 1
        elif [ $test -eq 84 ]
        then
            echo "Error invalid command given, please refer to usage statement printed!"
            exit 1
        # DEFAULT
        elif [ $test -eq 139 ]
        then
            echo "Error there was a memory error, please try again or use different parameters!"
            exit 1
        elif [ $test -eq 138 ]
        then
            echo "Error there was a memory error, please try again or use different parameters!"
            exit 1
        elif [ $test -eq 10 ]
        then
            echo "Error there was a memory error, please try again or use different parameters!"
            exit 1
        #malloc2DArray
        elif [ $test -eq 113 ]
        then
            echo "ERROR: Could not Malloc memory needed with current matrix configuration supplied!" 
            exit 1
        #fill2DArray - None
        #writeToFile
        elif [ $test -eq 102 ]
        then
            echo "Error opening the file!"
            exit 1
        elif [ $test -eq 101 ]
        then 
            echo "Error writing rows to file!"
            exit 1
        elif [ $test -eq 100 ]
        then
            echo "Error writing cols to file!"
            exit 1
        elif [ $test -eq 99 ]
        then
            echo "Error closing file after being written!"
            exit 1
        #getRowsCols
        elif [ $test -eq 107 ]
        then
            echo "Error opening file!"
            exit 1
        elif [ $test -eq 106 ]
        then
            echo "Error reading rows from file!"
            exit 1
        elif [ $test -eq 105 ]
        then
            echo "Error reading cols from file!"
            exit 1
        elif [ $test -eq 104 ]
        then
            echo "Error closing file after being read!"
            exit 1
        #getArray
        elif [ $test -eq 112 ]
        then
            echo "Can't open file with parameters given!"
            exit 1
        elif [ $test -eq 111 ]
        then
            echo "Can't get rows value from file given!"
            exit 1
        elif [ $test -eq 110 ]
        then
            echo "Can't get cols value from file given!"
            exit 1
        elif [ $test -eq 109 ]
        then
            echo "Can't read array elements from file given!"
            exit 1
        elif [ $test -eq 108 ]
        then
            echo "Error closing file after being read!"
            exit 1
        #print2DArray
        elif [ $test -eq 103 ]
        then
            echo "Error no readable data in array given!"
            exit 1
        #checksumA - None
        #checksumB - None
        #multiplySquareMatrices
        elif [ $test -eq 98 ]
        then
            echo "Cannot multiply matrices, could be an arithmetic error."
            exit 1
        #multiplyRegularMatrices
        elif [ $test -eq 97 ]
        then
            echo "Cannot multiply matrices, could be an arithmetic error."
            exit 1
        #writeErrorsToFile
        elif [ $test -eq 94 ]
        then
            echo "Error could not format row int error value for file writing!"
            exit 1
        elif [ $test -eq 93 ]
        then 
            echo "Error Could not format col int error value for file writing!"
            exit 1
        elif [ $test -eq 92 ]
        then
            echo "Error Could not open file!"
            exit 1
        elif [ $test -eq 91 ]
        then
            echo "Error writing row beginning string to file!"
            exit 1
        elif [ $test -eq 90 ]
        then
            echo "Error writing row error data to file!"
            exit 1
        elif [ $test -eq 89 ]
        then
            echo "Error writing col beginning string to file!"
            exit 1
        elif [ $test -eq 88 ]
        then
            echo "Error writing col error data to file!"
            exit 1
        elif [ $test -eq 87 ]
        then
            echo "Error closing file after being written!"
            exit 1
        #corruptArray
        elif [ $test -eq 96 ]
        then
            echo "Error bitIndex value invalid!"
            exit 1
        elif [ $test -eq 95 ]
        then
            echo "Error matrix was not successfully corrupted!"
            exit 1
        #writeToFile
        elif [ $test -eq 102 ]
        then
            echo "Error opening the file!"
            exit 1
        elif [ $test -eq 101 ]
        then 
            echo "Error writing rows to file!"
            exit 1
        elif [ $test -eq 100 ]
        then
            echo "Error writing cols to file!"
            exit 1
        elif [ $test -eq 99 ]
        then
            echo "Error closing file after being written!"
            exit 1
        #findFixErrors
        elif [ $test -eq 86 ]
        then
            echo "Error could not find any corrupted data values!"
            exit 1
        elif [ $test -eq 85 ]
        then
            echo "Error could not correct corrupted value in matrix!"
            exit 1
        fi
    fi

}

echo " "

./makeMatrix -m $rows1 -n $cols1 -l $lower1 -u $upper1 -o a.dat
test=$?
check_for_errors $test

./makeMatrix -m $rows2 -n $cols2 -l $lower2 -u $upper2 -o b.dat
test=$?
check_for_errors $test

./checksumA -a a.dat -o ab.dat
test=$?
check_for_errors $test

./checksumB -b b.dat -o bb.dat
test=$?
check_for_errors $test

./multiplyMatrix -a ab.dat -b bb.dat -o cb.dat
test=$?
check_for_errors $test

./detect -i cb.dat -o errors.txt
test=$?
check_for_errors $test

./corruptMatrix -r $corRow -c $corCol -b $bitToFlip -i cb.dat -o cb-corrupted.dat
test=$?
check_for_errors $test

./detect -i cb-corrupted.dat -o errors2.txt
test=$?
check_for_errors $test

./correct -i cb-corrupted.dat -o cb-corrected.dat
test=$?
check_for_errors $test

#------------------------

./printMatrix -i a.dat
test=$?
check_for_errors $test

printf '\n'

./printMatrix -i b.dat
test=$?
check_for_errors $test

printf '\n'

./printMatrix -i ab.dat
test=$?
check_for_errors $test

printf '\n'

./printMatrix -i bb.dat
test=$?
check_for_errors $test

printf '\n'

./printMatrix -i cb.dat
test=$?
check_for_errors $test

printf '\n'

./printMatrix -i cb-corrupted.dat
test=$?
check_for_errors $test

printf '\n'

./printMatrix -i cb-corrected.dat
test=$?
check_for_errors $test

printf '\n'
