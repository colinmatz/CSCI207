# Colin Matz / 12-2-2022 / Proj 1 - Phase 3
# THIS SCRIPT FILE IS MADE USING THE STANDARD GIVEN FOR SCRIPT FILE USAGE IN PHASE 3 BY DR. JONES

./makeMatrix.exe -m 5 -n 4 -l 1.0 -u 1.00001 -o a.dat
Start-Sleep -s 1
./makeMatrix.exe -m 4 -n 3 -l 1.0 -u 1.00001 -o b.dat

./printMatrix.exe -i a.dat
Write-Host " "
./printMatrix.exe -i b.dat
Write-Host " "
./checksumA.exe -a a.dat -o ab.dat
./checksumB.exe -b b.dat -o bb.dat

./printMatrix.exe -i ab.dat
Write-Host " "
./printMatrix.exe -i bb.dat
Write-Host " "

./multiplyMatrix.exe -a ab.dat -b bb.dat -o cb.dat

./printMatrix.exe -i cb.dat
Write-Host " "

./detect.exe -i cb.dat -o errors.txt

./corruptMatrix.exe -r 4 -c 3 -b 23 -i cb.dat -o cb-corrupted.dat

./printMatrix.exe -i cb-corrupted.dat
Write-Host " "

./detect.exe -i cb-corrupted.dat -o errors2.txt

./correct.exe -i cb-corrupted.dat -o cb-corrected.dat

./printMatrix.exe -i cb-corrected.dat
Write-Host " "