CC=gcc
CFLAGS=-Wall -g -Wpedantic
LFLAGS=-lm
PROGS = makeMatrix printMatrix checksumA checksumB multiplyMatrix corruptMatrix detect correct
PROGS2 = makeMatrix.exe printMatrix.exe checksumA.exe checksumB.exe multiplyMatrix.exe corruptMatrix.exe detect.exe correct.exe
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
	
corruptMatrix: corruptMatrix.o genHelp.o
	$(CC) $(CCOPT) $(LFLAGS) -o corruptMatrix corruptMatrix.o genHelp.o
	
detect: detect.o genHelp.o
	$(CC) $(CCOPT) -o detect detect.o genHelp.o $(LFLAGS)
	
correct: correct.o genHelp.o
	$(CC) $(CCOPT) $(LFLAGS) -o correct correct.o genHelp.o

makeMatrix.o: makeMatrix.c genHelp.h
	$(CC) $(CCOPT) $(CFLAGS) -c makeMatrix.c

printMatrix.o: printMatrix.c genHelp.h
	$(CC) $(CCOPT) $(CFLAGS) -c printMatrix.c

checksumA.o:	checksumA.c genHelp.h
	$(CC) $(CCOPT) $(CFLAGS) -c checksumA.c

checksumB.o:	checksumB.c genHelp.h
	$(CC) $(CCOPT) $(CFLAGS) -c checksumB.c

multiplyMatrix.o: multiplyMatrix.c genHelp.h
	$(CC) $(CCOPT) $(CFLAGS) -c multiplyMatrix.c

genHelp.o: genHelp.c genHelp.h
	$(CC) $(CCOPT) $(CFLAGS) -c genHelp.c
	
corruptMatrix.o: corruptMatrix.c genHelp.h
	$(CC) $(CCOPT) $(CFLAGS) -c corruptMatrix.c
	
detect.o: detect.c genHelp.h
	$(CC) $(CCOPT) $(CFLAGS) -c detect.c
	
correct.o: correct.c genHelp.h
	$(CC) $(CCOPT) $(CFLAGS) -c correct.c

clean:
	del -f *.o $(PROGS2) *.dat *.txt
