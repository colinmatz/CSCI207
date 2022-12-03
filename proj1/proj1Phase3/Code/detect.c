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
	int rowErr = -1;
	int colErr = -1;
	int* rowErrP = &rowErr;
	int* colErrP = &colErr;
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
			printf("Usage: ./detect -i <input file name> -o <output file name>\n");
			exit(84);
		}
	
	getRowsCols (&rows, &cols, fN);
	
	/* Function that mallocs a 2D array*/
	malloc2DArray(&C, rows, cols);
	
	getArray(C, rows, cols, fN);
	
	/* finds and sets col value where error occurs */
	detectColError(rows, cols, C, colErrP);
	/* finds and sets row value where error occurs */
	detectRowError(rows, cols, C, rowErrP);
    /* writes to the output file data to show where error cell is located in matrix provided */
    writeErrorsToFile(rowErr, colErr, fN2);
	
	/* FREE BLOCK */
	free(C);
	
}
