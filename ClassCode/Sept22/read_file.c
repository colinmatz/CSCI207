#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int main (int argc, char** argv) {

	// check to see if the right number of parameters were passed
	if(argc!=2) {
		printf("usage: %s <file name to read from> \n", argv[0]);
		exit(1);
	}

	// FILE *  fopen(const char * restrict path, const char * restrict mode);
	FILE *f = fopen(argv[1]   , "r"  );
	int item;
	for(int i=0; i<5; i++ ) {
		// size_t fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
		fread(&item, sizeof(int), 1, f);
		printf("Item %d from file is = %d \n", i, item);
		
	}
	fclose(f);

  return 0;
}
