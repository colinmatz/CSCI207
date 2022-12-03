# Colin Matz / 12-2-2022 / Proj 1 - Phase 3
# THIS SCRIPT IS MADE TO SHOW THIS CODE WORKING WITH RANDOM COMBINATIONS AND IS BASED OFF OF TESTSCRIPT2.SH
# THIS SCRIPT ALSO CHECKS FOR CUSTOM EXIT ERROR CODES FROM EACH FUNC AND RESPONDS ACCORDINGLY

caseCount=5 # CHANGE ONLY THIS VALUE AND THAT WILL CHANGE AMOUNT OF ITERATIONS RAN

originalCount=$caseCount
currentRun=1
noErrCount=0
multErr=0
invalCommandErr=0
memErr=0
malErr=0
writeFileErr=0
getRowsColsErr=0
getArrayErr=0
printErr=0
multRegErr=0
writeEtoFileErr=0
corruptArrErr=0
findFixErr=0

make

echo " "

while [[ $caseCount -gt 0 ]];
do
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

    echo "----------------------------"
    echo "- This is run iteration: $currentRun -"
    echo "----------------------------"


    check_for_errors () {
        test=$1

        if [ $test -gt 0 ] 
        then 
            # MAIN
            if [ $test -eq 83 ]
            then
                echo "The matrices provided cannot be multiplied!"
                multErr=$((multErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 84 ]
            then
                echo "Error invalid command given, please refer to usage statement printed!"
                invalCommandErr=$((invalCommandErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            # DEFAULT
            elif [ $test -eq 139 ]
            then
                echo "Error there was a memory error, please try again or use different parameters!"
                memErr=$((memErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 138 ]
            then
                echo "Error there was a memory error, please try again or use different parameters!"
                memErr=$((memErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 10 ]
            then
                echo "Error there was a memory error, please try again or use different parameters!"
                memErr=$((memErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            #malloc2DArray
            elif [ $test -eq 113 ]
            then
                echo "ERROR: Could not Malloc memory needed with current matrix configuration supplied!" 
                malErr=$((malErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            #fill2DArray - None
            #writeToFile
            elif [ $test -eq 102 ]
            then
                echo "Error opening the file!"
                writeFileErr=$((writeFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 101 ]
            then 
                echo "Error writing rows to file!"
                writeFileErr=$((writeFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 100 ]
            then
                echo "Error writing cols to file!"
                writeFileErr=$((writeFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 99 ]
            then
                echo "Error closing file after being written!"
                writeFileErr=$((writeFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            #getRowsCols
            elif [ $test -eq 107 ]
            then
                echo "Error opening file!"
                getRowsColsErr=$((getRowsColsErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 106 ]
            then
                echo "Error reading rows from file!"
                getRowsColsErr=$((getRowsColsErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 105 ]
            then
                echo "Error reading cols from file!"
                getRowsColsErr=$((getRowsColsErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 104 ]
            then
                echo "Error closing file after being read!"
                getRowsColsErr=$((getRowsColsErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            #getArray
            elif [ $test -eq 112 ]
            then
                echo "Can't open file with parameters given!"
                getArrayErr=$((getArrayErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 111 ]
            then
                echo "Can't get rows value from file given!"
                getArrayErr=$((getArrayErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 110 ]
            then
                echo "Can't get cols value from file given!"
                getArrayErr=$((getArrayErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 109 ]
            then
                echo "Can't read array elements from file given!"
                getArrayErr=$((getArrayErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 108 ]
            then
                echo "Error closing file after being read!"
                getArrayErr=$((getArrayErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            #print2DArray
            elif [ $test -eq 103 ]
            then
                echo "Error no readable data in array given!"
                printErr=$((printErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            #checksumA - None
            #checksumB - None
            #multiplyRegularMatrices
            elif [ $test -eq 97 ]
            then
                echo "Cannot multiply matrices, could be an arithmetic error."
                multRegErr=$((multRegErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            #writeErrorsToFile
            elif [ $test -eq 94 ]
            then
                echo "Error could not format row int error value for file writing!"
                writeEtoFileErr=$((writeEtoFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 93 ]
            then 
                echo "Error Could not format col int error value for file writing!"
                writeEtoFileErr=$((writeEtoFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 92 ]
            then
                echo "Error Could not open file!"
                writeEtoFileErr=$((writeEtoFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 91 ]
            then
                echo "Error writing row beginning string to file!"
                writeEtoFileErr=$((writeEtoFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 90 ]
            then
                echo "Error writing row error data to file!"
                writeEtoFileErr=$((writeEtoFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 89 ]
            then
                echo "Error writing col beginning string to file!"
                writeEtoFileErr=$((writeEtoFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 88 ]
            then
                echo "Error writing col error data to file!"
                writeEtoFileErr=$((writeEtoFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 87 ]
            then
                echo "Error closing file after being written!"
                writeEtoFileErr=$((writeEtoFileErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            #corruptArray
            elif [ $test -eq 96 ]
            then
                echo "Error bitIndex value invalid!"
                corruptArrErr=$((corruptArrErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 95 ]
            then
                echo "Error matrix was not successfully corrupted!"
                corruptArrErr=$((corruptArrErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            #findFixErrors
            elif [ $test -eq 86 ]
            then
                echo "Error could not find any corrupted data values!"
                findFixErr=$((findFixErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
            elif [ $test -eq 85 ]
            then
                echo "Error could not correct corrupted value in matrix!"
                findFixErr=$((findFixErr+1))
                currentRun=$((currentRun+1))
                caseCount=$((caseCount-1))
                continue
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

    # -------- PRINT BLOCK --------

    echo "Original Matrix 1: "
    ./printMatrix -i a.dat
    test=$?
    check_for_errors $test

    printf '\n'
    echo "Original Matrix 2: "
    ./printMatrix -i b.dat
    test=$?
    check_for_errors $test

    printf '\n'
    echo "Matrix 1 w/ Checksum Row: "
    ./printMatrix -i ab.dat
    test=$?
    check_for_errors $test

    printf '\n'
    echo "Matrix 2 w/ Checksum Col: "
    ./printMatrix -i bb.dat
    test=$?
    check_for_errors $test

    printf '\n'
    echo "Multiplied Matrices 1 & 2 and made Matrix 3: "
    ./printMatrix -i cb.dat
    test=$?
    check_for_errors $test

    printf '\n'
    echo "Matrix 3 Corrupted: "
    ./printMatrix -i cb-corrupted.dat
    test=$?
    check_for_errors $test

    printf '\n'
    echo "Matrix 3 Corrected: "
    ./printMatrix -i cb-corrected.dat
    test=$?
    check_for_errors $test

    printf '\n'

    noErrCount=$((noErrCount+1))
    currentRun=$((currentRun+1))
    caseCount=$((caseCount-1))

    sleep 1

done

make clean

touch testScriptLog.txt
printf "Amount of runs ran: $originalCount \n" > testScriptLog.txt

printf " \n" >> testScriptLog.txt

printf "Amount of runs with no errors: $noErrCount \n" >> testScriptLog.txt
printf "Amount of runs with arithmetic multiplication errors: $multErr \n" >> testScriptLog.txt
printf "Amount of runs with invalid command errors: $invalCommandErr \n" >> testScriptLog.txt
printf "Amount of runs with memory errors (SEGFAULTS, Bus Errors, Dumps, etc.): $memErr \n" >> testScriptLog.txt
printf "Amount of runs with malloc errors: $malErr \n" >> testScriptLog.txt
printf "Amount of runs with regular file writing errors: $writeFileErr \n" >> testScriptLog.txt
printf "Amount of runs with retrieving rows and cols errors: $getRowsColsErr \n" >> testScriptLog.txt
printf "Amount of runs with retrieving array errors: $getArrayErr \n" >> testScriptLog.txt
printf "Amount of runs with printing errors: $printErr \n" >> testScriptLog.txt
printf "Amount of runs with matrix multiplication func errors: $multRegErr \n" >> testScriptLog.txt
printf "Amount of runs with error file writing errors: $writeEtoFileErr \n" >> testScriptLog.txt
printf "Amount of runs with corrupt array errors: $corruptArrErr \n" >> testScriptLog.txt
printf "Amount of runs with find and fix corrupt errors: $findFixErr \n" >> testScriptLog.txt

