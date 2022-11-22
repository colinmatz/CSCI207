/* Colin Matz, Oct 26 2022, CSCI 207, Proj1 - Phase 1 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include "genUtil.h"
 
int main (int argc, char** argv) { 
	
	/* SETTING INITIAL VALUES */
	char* fN = argv[2];
	char* fN2 = argv[4];
	char* fN3 = argv[6];
	int* A;
	double** B;
	double* C;
	int* D;
	double** E;
	double* F;
	double** res;
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
	
	/* CALLING ALL FUNCTIONS NEEDED WITH ERROR CHECKING */
	
	int c1 = getDat(fN, &A, &C);
	if (c1 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int R1 = A[0];
	int C1 = A[1];
	
	int c2 = amal(&B, R1, C1);
	if (c2 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}

	int c3 =fillmal2(B, C, R1, C1);
	if (c3 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int c4 = getDat(fN2, &D, &F);
	if (c4 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int R2 = D[0];
	int C2 = D[1];
	
	int c5 = amal(&E, R2, C2);
	if (c5 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int c6 = fillmal2(E, F, R2, C2);
	if (c6 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int c7 = amal(&res, R1, C2);
	
	if (c7 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	if (R1 == R2 && C1 == C2) {
		int c8 = multSquare(R1, res, B, E);
		if (c8 != 1){
			printf("\nProgram Suspended.. For your safety ;)\n");
			exit(0);
		}
	}
 	
 	if (C1 == R2) {
 		int c9 = recSquare(R1, R2, C2, res, B, E);
 		if (c9 != 1){
			printf("\nProgram Suspended.. For your safety ;)\n");
			exit(0);
		}
        }
 	
 	else {
 		printf("ERROR: The matrices provided cannot be multiplied!\nPlease ensure Matrix 1's Column number matches the value of Matrix 2's Row number OR that they are BOTH equal in size (2x2, etc..)\n");
 		exit(0);
 	}
	
	int c10 = malInts(&G, R1, C2);
	
	if (c10 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int c11 = writeFile(G, res, R1, C2, fN3);
	
	if (c11 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
 	free(A);
 	free(B);
 	free(C);
 	free(D);
 	free(E);
 	free(F);
 	free(G);
 	free(res);
      	
}
