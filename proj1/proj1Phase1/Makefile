CC=gcc
CFLAGS=-Wall -g -Wpedantic
LFLAGS=-lm
PROGS = makeMatrix printMatrix checksumA checksumB multiplyMatrix
CCOPT =-std=c99

all:	$(PROGS)

makeMatrix:	makeMatrix.o genHelp.o
	$(CC) $(CCOPT) $(LFLAGS) -o makeMatrix makeMatrix.o genHelp.o

printMatrix: printMatrix.o genHelp.o
	$(CC) $(CCOPT) -o printMatrix printMatrix.o genHelp.o $(LFLAGS)

checksumA:	checksumA.o genHelp.o
	$(CC) $(CCOPT) $(LFLAGS) -o checksumA checksumA.o genHelp.o

checksumB:	checksumB.o genHelp.o
	$(CC) $(CCOPT) $(LFLAGS) -o checksumB checksumB.o genHelp.o

multiplyMatrix:	multiplyMatrix.o genHelp.o
	$(CC) $(CCOPT) $(LFLAGS) -o multiplyMatrix multiplyMatrix.o genHelp.o

makeMatrix.o: makeMatrix.c genUtil.h
	$(CC) $(CCOPT) $(CFLAGS) -c makeMatrix.c

printMatrix.o: printMatrix.c genUtil.h
	$(CC) $(CCOPT) $(CFLAGS) -c printMatrix.c

checksumA.o:	checksumA.c genUtil.h
	$(CC) $(CCOPT) $(CFLAGS) -c checksumA.c

checksumB.o:	checksumB.c genUtil.h
	$(CC) $(CCOPT) $(CFLAGS) -c checksumB.c

multiplyMatrix.o: multiplyMatrix.c genUtil.h
	$(CC) $(CCOPT) $(CFLAGS) -c multiplyMatrix.c

genHelp.o: genHelp.c genUtil.h
	$(CC) $(CCOPT) $(CFLAGS) -c genHelp.c

clean:
	rm -f *.o $(PROGS) *.dat
