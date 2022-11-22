#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int main (int argc, char** argv) {
	// check to see if the right number of parameters were passed
	if(argc!=2) {
		printf("usage: %s <file name to read from> \n", argv[0]);
		exit(1);
	}
	char* fileName = argv[1];
	int numInts = 0;

	int *A = read_file(fileName, &numInts);
	print_array(A, numInts);

	// what about the prior malloced A here
	// need to free ?

	/*

	// FILE *  fopen(const char * restrict path, const char * restrict mode);
	FILE *f = fopen(argv[1]   , "r"  );
	int item;
	int itemCount = 0;
	while(fread(&item, sizeof(int), 1, f) != 0) {
		// size_t fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
		printf("Item %d from file is = %d \n", itemCount, item);
		itemCount++;
	}

	fclose(f);
	*/


  	return 0;
}
