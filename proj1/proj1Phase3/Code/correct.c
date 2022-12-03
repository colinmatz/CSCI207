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

	char* fN;
	char* fN2;
	int opt;
	int** C;
	int rows = 0;
	int cols = 0;

	if (argc == 5){
			while ((opt = getopt(argc, argv, "i:o:")) != -1) {
				switch(opt) {
					case 'i':
						fN = optarg;
						break;
					case 'o':
						fN2 = optarg;
						break;
				}
			}
		}
		else {
			printf("Usage: ./correct -i <input file name> -o <output file name>\n");
			exit(84);
		}
	
	getRowsCols (&rows, &cols, fN);
	/* Function that mallocs a 2D array*/
	malloc2DArray(&C, rows, cols);

	getArray(C, rows, cols, fN);

	/* locates error cell, corrects the error cell, and prepares the array for writing to the output file */
	findFixErrors(C, fN, fN2, rows, cols);
	/* writes all data to output file */
	writeToFile(C, &rows, &cols, fN2);
	
	/* FREE BLOCK */
	free(C);
	
}

