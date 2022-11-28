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
	int* A;
	int** B;
	int* C;
	int* D;
	int** E;
	int* F;
	int** res;
	int* G;
	int opt;
	
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
	
	/* collects data from input file 1 */
	getDataFromFile(fN, &A, &C);
	
	/* setting rows1 and cols1 variables */
	int R1 = A[0];
	int C1 = A[1];
	
	/* Function that mallocs a 2D array*/
	malloc2DArray(&B, R1, C1);
	/* Fills 2D array with data collected from file 1 and put into input array */
	fill2DArray2(B, C, R1, C1);
	/* collects data from input file 2 */
	getDataFromFile(fN2, &D, &F);
	
	/* setting rows2 and cols2 variables */
	int R2 = D[0];
	int C2 = D[1];
	
	/* Function that mallocs a 2D array*/
	malloc2DArray(&E, R2, C2);
	/* Fills 2D array with data collected from file 2 and put into input array */
	fill2DArray2(E, F, R2, C2);
	/* Function that mallocs a 2D array*/
	malloc2DArray(&res, R1, C2);
	
	/* checks if the matrices are square (ex. 2x2 & 2x2, 3x3 & 3x3, etc.) */
	if (R1 == R2 && C1 == C2) {
		/* multiplies the matricies together and sets res array as the result array from the function */
		multiplySquareMatrices(R1, res, B, E);
	}
 	/* checks if the matrices are compatible to be multiplied together */
 	if (C1 == R2) {
 		/* multiplies the matricies together and sets res array as the result array from the function */
 		multiplyRegularMatrices(R1, R2, C2, res, B, E);
        }
 	/* error message to be printed if matricies cannot be multiplied (such that if they are not compatible) */
 	else {
 		printf("ERROR: The matrices provided cannot be multiplied!\nPlease ensure Matrix 1's Column number matches the value of Matrix 2's Row number OR that they are BOTH equal in size (2x2, etc..)\n");
 		exit(0);
 	}
 	
	/* writes all data to output file */
	writeToFile(&G, res, R1, C2, fN3);
	
	/* FREE BLOCK */
 	free(A);
 	free(B);
 	free(C);
 	free(D);
 	free(E);
 	free(F);
 	free(G);
 	free(res);
      	
}
