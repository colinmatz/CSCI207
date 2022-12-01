/* Colin Matz, Nov 20 2022, CSCI 207, Proj1 - Phase 3 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include "genHelp.h"
 
int main (int argc, char** argv) { 
	
	/* SETTING INITIAL VALUES */
	char* fN = argv[2];
	char* fN2 = argv[4];
	char* fN3 = argv[6];
	int** B;
	int** E;
	int** res;
	int opt;
	int rows1 = 0;
	int cols1 = 0;
	int rows2 = 0;
	int cols2 = 0;
	
	/* PARSING IN VALUES CODE (GETOPT) */
	if (argc == 7){
		while ((opt = getopt(argc, argv, "a:b:o:")) != -1) {
			switch(opt) {
				case 'a':
					fN = optarg;
					break;
				case 'b':
					fN2 = optarg;
					break;
				case 'o':
					fN3 = optarg;
					break;
			}
		}
	}
	else {
		printf("Usage: ./multiplyMatrix -a <Input 1 File Name> -b <Input 2 File Name> -o <Output File Name>\n");
		exit(0);
	}
	
	/* CALLING ALL FUNCTIONS NEEDED */
	
	getRowsCols (&rows1, &cols1, fN);
	
	/* Function that mallocs a 2D array*/
	malloc2DArray(&B, rows1, cols1);

	getArray(B, rows1, cols1, fN);

	// ----------------

	getRowsCols (&rows2, &cols2, fN2);
	
	/* Function that mallocs a 2D array*/
	malloc2DArray(&E, rows2, cols2);

	getArray(E, rows2, cols2, fN2);

	// -----------------

	/* Function that mallocs a 2D array*/
	malloc2DArray(&res, rows1, cols2);
	
	/* checks if the matrices are square (ex. 2x2 & 2x2, 3x3 & 3x3, etc.) */
	if (rows1 == rows2 && cols1 == cols2) {
		/* multiplies the matricies together and sets res array as the result array from the function */
		multiplySquareMatrices(rows1, res, B, E);
	}
 	/* checks if the matrices are compatible to be multiplied together */
 	if (cols1 == rows2) {
 		/* multiplies the matricies together and sets res array as the result array from the function */
 		multiplyRegularMatrices(rows1, rows2, cols2, res, B, E);
        }
 	/* error message to be printed if matricies cannot be multiplied (such that if they are not compatible) */
 	else {
 		printf("ERROR: The matrices provided cannot be multiplied!\nPlease ensure Matrix 1's Column number matches the value of Matrix 2's Row number OR that they are BOTH equal in size (2x2, etc..)\n");
 		exit(0);
 	}
 	
	/* writes all data to output file */
	writeToFile(res, rows1, cols2, fN3);
	
	/* FREE BLOCK */
 	free(B);
 	free(E);
 	free(res);
      	
}
