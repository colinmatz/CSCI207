./makeMatrix -m 4 -n 4 -l 1 -u 9 -o a.dat
sleep 1
./makeMatrix -m 4 -n 4 -l 1 -u 9 -o b.dat

./multiplyMatrix -a a.dat -b b.dat -o c.dat

./printMatrix -i c.dat
printf '\n'

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

./corruptMatrix -r 2 -c 3 -b 16 -i cb.dat -o cb-corrupted.dat

./printMatrix -i cb-corrupted.dat
printf '\n'

./detect -i cb-corrupted.dat -o errors2.txt

./correct -i cb-corrupted.dat -o cb-corrected.dat

./printMatrix -i cb-corrected.dat
printf '\n'