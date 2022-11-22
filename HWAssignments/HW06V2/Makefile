CC=gcc
CFLAGS=-Wall -g -Wpedantic
LFLAGS=-lm
PROGS = my_file_copy make_a_file
CCOPT =-std=c99

all:	$(PROGS)

my_file_copy: my_file_copy.c
	$(CC) $(CCOPT) $(LFLAGS) $(CFLAGS) -o my_file_copy  my_file_copy.c

make_a_file: make_a_file.c
	$(CC) $(CCOPT) $(LFLAGS) $(CFLAGS) -o make_a_file make_a_file.c

clean:
	rm -f *.o $(PROGS) *.dat
