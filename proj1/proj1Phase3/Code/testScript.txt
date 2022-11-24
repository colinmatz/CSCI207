./makeMatrix -m 5 -n 4 -l 1 -u 10 -o a.dat
./makeMatrix -m 4 -n 6 -l 1 -u 10 -o b.dat

./printMatrix -i a.dat
printf '\n'
./printMatrix -i b.dat
printf '\n'
./checksumA -a a.dat -o ab.dat
./checksumB -b b.dat -o bb.dat

./printMatrix -i ab.dat
printf '\n'
./printMatrix -i bb.dat
printf '\n'

./multiplyMatrix -a ab.dat -b bb.dat -o cb.dat

./printMatrix -i cb.dat
printf '\n'

./detect -i cb.dat -o errors.txt

./corruptMatrix -r 4 -c 3 -b 23 -i cb.dat -o cb-corrupted.dat

./printMatrix -i cb-corrupted.dat
printf '\n'

./detect -i cb-corrupted.dat -o errors2.txt

./correct -i cb-corrupted.dat -o cb-corrected.dat

./printMatrix -i cb-corrected.dat
printf '\n'