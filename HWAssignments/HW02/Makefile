CC=gcc
CFLAGS=-Wall -g -Wpedantic
LFLAGS=-lm
PROGS = callers write_file read_file

all:	$(PROGS)

callers:	callers.o help.o
	$(CC) $(LFLAGS) -o callers callers.o help.o

write_file:	write_file.o help.o
	$(CC) $(LFLAGS) -o write_file write_file.o help.o

read_file:	read_file.o help.o
	$(CC) $(LFLAGS) -o read_file read_file.o help.o

callers.o:	callers.c help.h
	$(CC) $(CFLAGS) -c callers.c

write_file.o:	write_file.c help.h
	$(CC) $(CFLAGS) -c write_file.c

read_file.o:	read_file.c help.h
	$(CC) $(CFLAGS) -c read_file.c

help.o:	help.c help.h
	$(CC) $(CFLAGS) -c help.c

clean:
	rm -f *.o $(PROGS) *.dat
