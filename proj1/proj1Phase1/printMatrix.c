/* Colin Matz, Oct 26 2022, CSCI 207, Proj1 - Phase 1 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include "genUtil.h"

int main (int argc, char** argv) {

	/* SETTING INITIAL VALUES */
	int opt;
	int* D;
	double* E;
	char* fN;
	double** B;
	
	/* PARSING IN VALUES CODE (GETOPT) */
	if (argc == 3){
		int check = strcmp(argv[1], "-i");
		if (check == 0) {
			while ((opt = getopt(argc, argv, "i:")) != -1) {
				switch(opt) {
					case 'i':
						fN = optarg;
						break;
				}
			}
		}
		else {
			printf("Usage: ./printMatrix -i <fileName>\n");
		exit(0);
		}
	}
	else {
		printf("Usage: ./printMatrix -i <fileName>\n");
		exit(0);
	}
	
	/* CALLING ALL FUNCTIONS NEEDED WITH ERROR CHECKING */
	
	int c1 = getDat(fN, &D, &E);
	
	if (c1 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int rows = D[0];
	int cols = D[1];
	
	int c2 = amal(&B, rows, cols);
	
	if (c2 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}

	int c3 = fillmal2(B, E, rows, cols);
	
	if (c3 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int c4 = print2D(B, rows, cols);
	
	if (c4 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	free(B);
	free(D);
	free(E);
	
}
