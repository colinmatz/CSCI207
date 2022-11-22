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
	
	/* collects data from input file */
	getDataFromFile(fN, &D, &E);
	
	/* setting rows and cols variables */
	int rows = D[0];
	int cols = D[1];
	
	/* Function that mallocs a 2D array*/
	malloc2DArray(&B, rows, cols);
	/* Fills 2D array with data collected from file and put into input array */
	fill2DArray2(B, E, rows, cols);
	/* prints data to console */
	print2DArray(B, rows, cols);
	
	/* FREE BLOCK */
	free(B);
	free(D);
	free(E);
	
}
