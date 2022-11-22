CC=g++
CCPFLAGS=-std=c++11
CFLAGS=-W -Wall -Wpedantic
PROGS = complex

all:	$(PROGS)

complex: complex.cpp
	$(CC) $(CCPFLAGS) $(CFLAGS) -o complex -p complex.cpp

clean:
	rm -f *.o $(PROGS) *.dat *.out
