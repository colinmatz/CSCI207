/* Colin Matz, Nov 20 2022, CSCI 207, Proj1 - Phase 3 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include "genHelp.h"

int main (int argc, char** argv) {

	/* SETTING INITIAL VALUES */
	int opt;
	char* fN;
	int** B = NULL;
	int rows = 0;
	int cols = 0;
	
	/* PARSING IN VALUES CODE (GETOPT) */
	if (argc == 3){
		int check = strcmp(argv[1], "-i");
		if (check == 0) {
			while ((opt = getopt(argc, argv, "i:")) != -1) {
				switch(opt) {
					case 'i':
						fN = optarg;
						break;
				}
			}
		}
		else {
			printf("Usage: ./printMatrix -i <fileName>\n");
		exit(0);
		}
	}
	else {
		printf("Usage: ./printMatrix -i <fileName>\n");
		exit(0);
	}

	getRowsCols (&rows, &cols, fN); 

	malloc2DArray(&B, rows, cols);

	getArray(B, rows, cols, fN);

	print2DArray(B, rows, cols);
	
	// FREE BLOCK 
	free(B);
	
}
