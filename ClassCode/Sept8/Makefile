CC=gcc
CFLAGS=-Wall -g -Wpedantic
LFLAGS=-lm

all: runmyprojmain

runmyprojmain: foo.o proj.o
	$(CC) $(LFLAGS) -o runmyprojmain foo.o proj.o

foo.o: foo.c foo.h
	$(CC) $(CFLAGS) -c foo.c

proj.o: proj.c foo.h
	$(CC) $(CFLAGS) -c proj.c

clean:
	rm -f *.o runmyprojmain
