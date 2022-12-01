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
	int** D;
	int opt;
	int rows = 0;
	int cols = 0;
	
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
	
	getRowsCols (&rows, &cols, fN);
	
	/* Function that mallocs a 2D array*/
	malloc2DArray(&D, rows, cols+1);
	/* Fills 2D array with data collected from file and put into input array */
	getArray(D, rows, cols, fN);
	/* creates and adds values to an added checksum col */
	checksumB(&D, rows, cols);
	/* writes all data to output file */
	writeToFile(D, rows, cols + 1, fN2);
	
	/* FREE BLOCK */	
	free(D);
}
