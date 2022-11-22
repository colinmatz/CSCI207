/* Colin Matz, Oct 26 2022, CSCI 207, Proj1 - Phase 1 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include "genUtil.h"

int main (int argc, char** argv) {

	/* SETTING INITIAL VALUES */
	char* fN;
	char* fN2;
	int* A;
	double* C;
	double** D;
	int* E;
	int opt;
	double** B;
	
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
		printf("Usage: ./checkSumB -a <Input File Name> -o <Output File Name>\n");
		exit(0);
	}
	
	/* CALLING ALL FUNCTIONS NEEDED WITH ERROR CHECKING */
	
	int c1 = getDat (fN, &A, &C);
	
	if (c1 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int rows = A[0];
	int cols = A[1];
	
	int c2 = amal(&B, rows, cols);
	
	if (c2 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}

	int c3 = fillmal2(B, C, rows, cols);
	
	if (c3 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int c4 = amal(&D, rows, cols+1);
	
	if (c4 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int c5 = fillmal2(D, C, rows, cols);
	
	if (c5 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int c6 = checksumB(&D, rows, cols);
	
	if (c6 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	cols = cols + 1;
	
	int c7 = malInts(&E, rows, cols);
	
	if (c7 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int c8 = writeFile(E, D, rows, cols, fN2);
	
	if (c8 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	free(E);	
	free(A);
	free(B);
	free(C);
	free(D);
}
