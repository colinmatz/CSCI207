// Colin Matz
// HW04 Ver. 2
// Sept 29, 2022

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

	return 0;
}
