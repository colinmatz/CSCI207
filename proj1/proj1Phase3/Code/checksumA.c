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
	int** B;
	int opt;
	int rows = 0;
	int cols = 0;
	
	/* PARSING IN VALUES CODE (GETOPT) */
	if (argc == 5){
		while ((opt = getopt(argc, argv, "a:o:")) != -1) {
			switch(opt) {
				case 'a':
					fN = optarg;
					break;
				case 'o':
					fN2 = optarg;
					break;
			}
		}
	}
	else {
		printf("Usage: ./checkSumA -a <Input File Name> -o <Output File Name>\n");
		exit(84);
	}
	
	/* CALLING ALL FUNCTIONS NEEDED WITH ERROR CHECKING */
	
	/* collects data from input file */
	getRowsCols (&rows, &cols, fN);
	/* Function that mallocs a 2D array with added row for checksum*/
	malloc2DArray(&B, rows + 1, cols);

	getArray(B, rows, cols, fN);

	/* creates and adds values to an added checksum row */
	checksumA(B, rows, cols);
	rows += 1;
	/* writes all data to output file */
	writeToFile(B, &rows, &cols, fN2);
	
	/* FREE BLOCK */
	free(B);

}
