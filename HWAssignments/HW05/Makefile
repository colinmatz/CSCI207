CC=gcc
CFLAGS=-Wall -g -Wpedantic
LFLAGS=-lm
PROGS = callers write_file read_file main_struct array_examples
CCOPT =-std=c99

all:	$(PROGS)

array_examples:	array_examples.o help.o
	$(CC) $(CCOPT) $(LFLAGS) -o array_examples array_examples.o help.o

main_struct: main_struct.c
	$(CC) $(CCOPT) $(LFLAGS) -o main_struct main_struct.c

callers:	callers.o help.o
	$(CC) $(CCOPT) $(LFLAGS) -o callers callers.o help.o

write_file:	write_file.o help.o
	$(CC) $(CCOPT) $(LFLAGS) -o write_file write_file.o help.o

read_file:	read_file.o help.o
	$(CC) $(CCOPT) $(LFLAGS) -o read_file read_file.o help.o

callers.o:	callers.c help.h
	$(CC) $(CCOPT) $(CFLAGS) -c callers.c

array_example.o:	array_example.c help.h
	$(CC) $(CCOPT) $(CFLAGS) -c array_example.c

write_file.o:	write_file.c help.h
	$(CC) $(CCOPT) $(CFLAGS) -c write_file.c

read_file.o:	read_file.c help.h
	$(CC) $(CCOPT) $(CFLAGS) -c read_file.c

help.o:	help.c help.h
	$(CC) $(CCOPT) $(CFLAGS) -c help.c

clean:
	rm -f *.o $(PROGS) *.dat
