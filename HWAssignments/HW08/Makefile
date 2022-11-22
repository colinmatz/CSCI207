iCC=gcc
CFLAGS=-Wall -g -Wpedantic
LFLAGS=-lm
PROGS = test-program
CCOPT =-std=c99

all:	$(PROGS)

test-program: test-program.o complex.o
	$(CC) $(CCOPT) -o test-program  test-program.o complex.o $(LFLAGS)

test-program.o: test-program.c complex.h
	$(CC) $(CCOPT) $(CFLAGS) -c test-program.c $(LFLAGS)

complex.o: complex.c complex.h
	$(CC) $(CCOPT) $(CFLAGS) -c complex.c $(LFLAGS)

clean:
	rm -f *.o $(PROGS) *.dat
