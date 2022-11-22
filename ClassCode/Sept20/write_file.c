#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int main(int argc, char** argv) {

	// check to see if right number of parameters were passed
	if(argc!=3) {
		printf("usage: %s <file name to write to> <number of intefers to write> \n", argv[0]);
	}
	// FILE * fopen(const char * restrict path, const char * restrict mode);
	FILE *f = fopen(argv[1], "w");
	
	for(int i=0; i<atoi(argv[2]); i++){
	
	// first argument has to be an *address
		fwrite(&i, sizeof(int), 1, f); //will write i to the file 1 (third argument) interation at a time
	
	}
	
	fclose(f);

	return 0;	
}
