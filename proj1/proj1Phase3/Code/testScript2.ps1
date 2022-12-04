# Colin Matz / 12-2-2022 / Proj 1 - Phase 3
# THIS SCRIPT IS MADE TO SHOW THIS CODE WORKING WITH RANDOM COMBINATIONS AND IS BASED OFF OF TESTSCRIPT2.SH
# THIS SCRIPT ALSO CHECKS FOR CUSTOM EXIT ERROR CODES FROM EACH FUNC AND RESPONDS ACCORDINGLY

$global:caseCount = 100 # CHANGE ONLY THIS VALUE AND THAT WILL CHANGE AMOUNT OF ITERATIONS RAN

$global:originalCount = $caseCount
$global:currentRun = 1
$global:noErrCount = 0
$global:multErr = 0
$global:invalCommandErr = 0
$global:memErr = 0
$global:malErr = 0
$global:writeFileErr = 0
$global:getRowsColsErr = 0
$global:getArrayErr = 0
$global:printErr = 0
$global:multRegErr = 0
$global:writeEtoFileErr = 0
$global:corruptArrErr = 0
$global:findFixErr = 0

make

Write-Host " "

while ( $caseCount -gt 0 ) {
    $rows1 = Get-Random -Minimum 2 -Maximum 6
    $cols1 = Get-Random -Minimum 2 -Maximum 6
    $rows2 = $cols1
    $cols2 = Get-Random -Minimum 2 -Maximum 6
    $bitToFlip = Get-Random -Minimum 1 -Maximum 32
    $corRow = Get-Random -Maximum $rows1
    $corCol = Get-Random -Maximum $cols2
    $lower1 = Get-Random -Minimum 1 -Maximum 7
    $upper1 = Get-Random -Minimum $lower1 -Maximum 15
    $lower2 = Get-Random -Minimum 1 -Maximum 7
    $upper2 = Get-Random -Minimum $lower2 -Maximum 15

    Write-Host "----------------------------"
    Write-Host "- This is run iteration: $currentRun -"
    Write-Host "----------------------------"

    function check_for_errors ($test) {

        if ( $test -gt 0 ) {
            # MAIN
            if ( $test -eq 83 ){
                Write-Host "The matrices provided cannot be multiplied!"
                $global:multErr = ( $global:multErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 84 ){
                Write-Host "Error invalid command given, please refer to usage statement printed!"
                $global:invalCommandErr = ( $global:invalCommandErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            # DEFAULT
            elseif ( $test -eq 139 ){
                Write-Host "Error there was a memory error, please try again or use different parameters!"
                $global:memErr = ( $global:memErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 138 ) {
                Write-Host "Error there was a memory error, please try again or use different parameters!"
                $global:memErr = ( $global:memErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            
            elseif ( $test -eq 10 ) {
                Write-Host "Error there was a memory error, please try again or use different parameters!"
                $global:memErr = ( $global:memErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            #malloc2DArray
            elseif ( $test -eq 113 ) {
                Write-Host "ERROR: Could not Malloc memory needed with current matrix configuration supplied!" 
                $global:malErr = ( $global:malErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            #fill2DArray - None
            #writeToFile
            elseif ( $test -eq 102 ) {
                Write-Host "Error opening the file!"
                $global:writeFileErr = ( $global:writeFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 101 ) { 
                Write-Host "Error writing rows to file!"
                $global:writeFileErr = ( $global:writeFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 100 ) {
                Write-Host "Error writing cols to file!"
                $global:writeFileErr = ( $global:writeFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 99 ) {
                Write-Host "Error closing file after being written!"
                $global:writeFileErr = ( $global:writeFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            #getRowsCols
            elseif ( $test -eq 107 ) {
                Write-Host "Error opening file!"
                $global:getRowsColsErr = ( $global:getRowsColsErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 106 ) {
                Write-Host "Error reading rows from file!"
                $global:getRowsColsErr = ( $global:getRowsColsErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 105 ) {
                Write-Host "Error reading cols from file!"
                $global:getRowsColsErr = ( $global:getRowsColsErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 104 ) {
                Write-Host "Error closing file after being read!"
                $global:getRowsColsErr = ( $global:getRowsColsErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            #getArray
            elseif ( $test -eq 112 ) {
                Write-Host "Can't open file with parameters given!"
                $global:getArrayErr = ( $global:getArrayErr + 1 )
                $global:currentRun =  ( $global:currentRun + 1)
                $global:caseCount =  ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 111 ) {
                Write-Host "Can't get rows value from file given!"
                $global:getArrayErr = ( $global:getArrayErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 110 ) {
                Write-Host "Can't get cols value from file given!"
                $global:getArrayErr = ( $global:getArrayErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 109 ) {
                Write-Host "Can't read array elements from file given!"
                $global:getArrayErr = ( $global:getArrayErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 108 ) {
                Write-Host "Error closing file after being read!"
                $global:getArrayErr = ( $global:getArrayErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            #print2DArray
            elseif ( $test -eq 103 ) {
                Write-Host "Error no readable data in array given!"
                $global:printErr = ( $global:printErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            #checksumA - None
            #checksumB - None
            #multiplyRegularMatrices
            elseif ( $test -eq 97 ) {
                Write-Host "Cannot multiply matrices, could be an arithmetic error."
                $global:multRegErr = ( $global:multRegErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue
            #writeErrorsToFile
            elseif ( $test -eq 94 ) {
                Write-Host "Error could not format row int error value for file writing!"
                $global:writeEtoFileErr = ( $global:writeEtoFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 93 ) { 
                Write-Host "Error Could not format col int error value for file writing!"
                $global:writeEtoFileErr = ( $global:writeEtoFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 92 ) {
                Write-Host "Error Could not open file!"
                $global:writeEtoFileErr = ( $global:writeEtoFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 91 ) {
                Write-Host "Error writing row beginning string to file!"
                $global:writeEtoFileErr = ( $global:writeEtoFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 90 ) {
                Write-Host "Error writing row error data to file!"
                $global:writeEtoFileErr = ( $global:writeEtoFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 89 ) {
                Write-Host "Error writing col beginning string to file!"
                $global:writeEtoFileErr = ( $global:writeEtoFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 88 ) {
                Write-Host "Error writing col error data to file!"
                $global:writeEtoFileErr = ( $global:writeEtoFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 87 ) {
                Write-Host "Error closing file after being written!"
                $global:writeEtoFileErr = ( $global:writeEtoFileErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            #corruptArray
            elseif ( $test -eq 96 ) {
                Write-Host "Error bitIndex value invalid!"
                $global:corruptArrErr = ( $global:corruptArrErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 95 ) {
                Write-Host "Error matrix was not successfully corrupted!"
                $global:corruptArrErr = ( $global:corruptArrErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            #findFixErrors
            elseif ( $test -eq 86 ) {
                Write-Host "Error could not find any corrupted data values!"
                $global:findFixErr = ( $global:findFixErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            elseif ( $test -eq 85 ) {
                Write-Host "Error could not correct corrupted value in matrix!"
                $global:findFixErr = ( $global:findFixErr + 1 )
                $global:currentRun = ( $global:currentRun + 1)
                $global:caseCount = ( $global:caseCount - 1)
                continue 
            }
            }
        }

    }

    Write-Host " "

    ./makeMatrix.exe -m $rows1 -n $cols1 -l $lower1 -u $upper1 -o a.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    ./makeMatrix.exe -m $rows2 -n $cols2 -l $lower2 -u $upper2 -o b.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    ./checksumA.exe -a a.dat -o ab.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    ./checksumB.exe -b b.dat -o bb.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    ./multiplyMatrix.exe -a ab.dat -b bb.dat -o cb.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    ./detect.exe -i cb.dat -o errors.txt
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    ./corruptMatrix.exe -r $corRow -c $corCol -b $bitToFlip -i cb.dat -o cb-corrupted.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    ./detect.exe -i cb-corrupted.dat -o errors2.txt
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    ./correct.exe -i cb-corrupted.dat -o cb-corrected.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    # -------- PRINT BLOCK --------

    Write-Host "Original Matrix 1: "
    ./printMatrix -i a.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    Write-Host ' '
    Write-Host "Original Matrix 2: "
    ./printMatrix -i b.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    Write-Host ' '
    Write-Host "Matrix 1 w/ Checksum Row: "
    ./printMatrix -i ab.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    Write-Host ' '
    Write-Host "Matrix 2 w/ Checksum Col: "
    ./printMatrix -i bb.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    Write-Host ' '
    Write-Host "Multiplied Matrices 1 & 2 and made Matrix 3: "
    ./printMatrix -i cb.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    Write-Host ' '
    Write-Host "Matrix 3 Corrupted: "
    ./printMatrix -i cb-corrupted.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    Write-Host ' '
    Write-Host "Matrix 3 Corrected: "
    ./printMatrix -i cb-corrected.dat
    Start-Sleep -s 1
    $test = $LASTEXITCODE
    check_for_errors $test

    Write-Host ' '

    $global:noErrCount = ($global:noErrCount + 1)
    $global:currentRun =  ($global:currentRun + 1)
    $global:caseCount =  ($global:caseCount - 1)

    #Start-Sleep -s 1

}

make clean

New-Item ./testScriptLog.txt
"Amount of runs ran: $global:originalCount" | Out-File -FilePath testScriptLog.txt

" " | Out-File -FilePath testScriptLog.txt -Append

"Amount of runs with no errors: $global:noErrCount" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with arithmetic multiplication errors: $global:multErr" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with invalid command errors: $global:invalCommandErr" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with memory errors (SEGFAULTS, Bus Errors, Dumps, etc.): $global:memErr" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with malloc errors: $global:malErr" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with regular file writing errors: $global:writeFileErr" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with retrieving rows and cols errors: $global:getRowsColsErr" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with retrieving array errors: $global:getArrayErr" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with printing errors: $global:printErr" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with matrix multiplication func errors: $global:multRegErr" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with error file writing errors: $global:writeEtoFileErr" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with corrupt array errors: $global:corruptArrErr" | Out-File -FilePath testScriptLog.txt -Append
"Amount of runs with find and fix corrupt errors: $global:findFixErr" | Out-File -FilePath testScriptLog.txt -Append

