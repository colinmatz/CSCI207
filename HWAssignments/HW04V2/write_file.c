// Colin Matz
// HW04 Ver. 2
// Sept 29, 2022

#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int main (int argc, char** argv) {

	// check to see if the right number of parameters were passed
	if(argc!=3) {
		printf("usage: %s <file name to write to> <number of integers to write> \n", argv[0]);
		exit(1);
	}

	// FILE *  fopen(const char * restrict path, const char * restrict mode);
	FILE *f = fopen(argv[1]   , "w"  );
	
	if (!f) {
		perror("ERROR: ");
	}

	for(int i=0; i<atoi(argv[2]); i++ ) {
		fwrite(&i, sizeof(int), 1, f); // will write i to file, one iteration at a time 
	}

	fclose(f);

  return 0;
}
