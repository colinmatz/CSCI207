/* Colin Matz, Nov 9 2022, CSCI 207, Proj1 - Phase 2 V2 */

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
	int* A;
	double* B;
	double** C;

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
	/* locates error cell, corrects the error cell, and prepares the array for writing to the output file */
	findFixErrors(C, fN, fN2, fR, fC);
	/* writes all data to output file */
	writeToFile(A, C, fR, fC, fN2);
	
	/* FREE BLOCK */
	free(A);
	free(B);
	free(C);
	
}

