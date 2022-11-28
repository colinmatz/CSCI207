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

	int cR;
	int cC;
	int bitIndex;
	char* fN = argv[9];
	char* fN2 = argv[11];
	int opt;
	int* A;
	int* B;
	int** C;

	if (argc == 11){
			while ((opt = getopt(argc, argv, "r:c:b:i:o:")) != -1) {
				switch(opt) {
					case 'r':
						cR = atoi(optarg);
						break;
					case 'c':
						cC = atoi(optarg);
						break;
					case 'b':
						bitIndex = atoi(optarg);
						break;
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
			printf("Usage: ./corruptMatrix -r <row to change> -c <column to change> -b <bit index to flip> -i <input file name> -o <output file name>\n");
			exit(0);
		}
	
	/* collects data from input file */
	getDataFromFile(fN, &A, &B);
	
	/* setting rows and cols variables */
	int fR = A[0];
	int fC = A[1];
	
	/* Function that mallocs a 2D array*/
	malloc2DArray(&C, fR, fC);
	/* Fills 2D array with data collected from file and put into input array */
	fill2DArray2(C, B, fR, fC);
	
	/* NEW FUNCTION IMPLEMENTED FOR PHASE 2*/
	/* corrupts a value at the intersect of passed in row/col by flipping a bit indicated by bitIndex */
	corruptArray(C, cR, cC, bitIndex);
	
	/* writes all data to output file */
	writeToFile(C, fR, fC, fN2);
		
	/* FREE BLOCK */
	free(A);
	free(B);
	free(C);
}
