rows1=$((2 + $RANDOM % 5))
cols1=$((2 + $RANDOM % 5))
rows2=$cols1
cols2=$((2 + $RANDOM % 5))
bitToFlip=$((1 + $RANDOM % 31))
corRow=$((1 + $RANDOM % ($rows1 - 1)))
corCol=$((1 + $RANDOM % ($cols2 - 1)))
lower1=$((1 + $RANDOM % 10))
upper1=$((($lower + 1) + $RANDOM % 30))
lower2=$((1 + $RANDOM % 10))
upper2=$((($lower + 1) + $RANDOM % 30))

./makeMatrix -m $rows1 -n $cols1 -l $lower1 -u $upper1 -o a.dat
./makeMatrix -m $rows2 -n $cols2 -l $lower2 -u $upper2 -o b.dat

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

./corruptMatrix -r $corRow -c $corCol -b $bitToFlip -i cb.dat -o cb-corrupted.dat

./printMatrix -i cb-corrupted.dat
printf '\n'

./detect -i cb-corrupted.dat -o errors2.txt

./correct -i cb-corrupted.dat -o cb-corrected.dat

./printMatrix -i cb-corrected.dat
printf '\n'