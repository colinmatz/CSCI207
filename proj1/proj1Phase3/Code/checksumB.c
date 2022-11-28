/* Colin Matz, Nov 20 2022, CSCI 207, Proj1 - Phase 3 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include "genHelp.h"

int main (int argc, char** argv) {

	/* SETTING INITIAL VALUES */
	char* fN;
	char* fN2;
	int* A;
	int* C;
	int** D;
	int* E;
	int opt;
	int** B;
	
	/* PARSING IN VALUES CODE (GETOPT) */
	if (argc == 5){
		while ((opt = getopt(argc, argv, "b:o:")) != -1) {
			switch(opt) {
				case 'b':
					fN = optarg;
					break;
				case 'o':
					fN2 = optarg;
					break;
			}
		}
	}
	else {
		printf("Usage: ./checkSumB -b <Input File Name> -o <Output File Name>\n");
		exit(0);
	}
	
	/* CALLING ALL FUNCTIONS NEEDED WITH ERROR CHECKING */
	
	/* collects data from input file */
	getDataFromFile(fN, &A, &C);
	
	/* setting rows and cols variables */
	int rows = A[0];
	int cols = A[1];
	
	/* Function that mallocs a 2D array*/
	malloc2DArray(&B, rows, cols);
	/* Fills 2D array with data collected from file and put into input array */
	fill2DArray2(B, C, rows, cols);
	/* Function that mallocs a 2D array*/
	malloc2DArray(&D, rows, cols+1);
	/* Fills 2D array with data collected from file and put into input array */
	fill2DArray2(D, C, rows, cols);
	/* creates and adds values to an added checksum col */
	checksumB(&D, rows, cols);
	/* adds checksum col to col total */
	cols = cols + 1;
	/* writes all data to output file */
	writeToFile(&E, D, rows, cols, fN2);
	
	/* FREE BLOCK */
	free(E);	
	free(A);
	free(B);
	free(C);
	free(D);
}
