./makeMatrix -m 5 -n 4 -l 1 -u 10 -o a.dat
./makeMatrix -m 4 -n 6 -l 1 -u 10 -o b.dat

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