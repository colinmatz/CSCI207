/* Colin Matz, Nov 20 2022, CSCI 207, Proj1 - Phase 3 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <time.h>
#include "genHelp.h"

int main (int argc, char** argv) {

	/* SETTING INITIAL VALUES */
	int opt;	
	int rows;
	int cols;
	int lower;
	int upper;
	char* ofn;
	int* C;
    int** A;
	
	/* PARSING IN VALUES CODE (GETOPT) */
	if (argc == 2 || argc == 11){
		int check = strcmp(argv[1], "-d");
		if (check == 0 || argc == 11) {
			while ((opt = getopt(argc, argv, "m:n:l:u:o:d")) != -1) {
				switch(opt) {
					case 'm':
						rows = atoi(optarg);
						break;
					case 'n':
						cols = atoi(optarg);
						break;
					case 'l':
						lower = atoi(optarg);
						break;
					case 'u':
						upper = atoi(optarg);
						break;
					case 'o':
						ofn = optarg;
						break;
					case 'd':
						rows = 5;
						cols = 6;
						lower = 1;
						upper = 100;
						ofn = "a.dat";
						printf("Parameters Assigned by Default \n");
						break;
				}
			}
		}
		else {
			printf("Usage: ./makeMatrix -m <Row Amount> -n <Col Amount> -l <Lower Bound for Numbers> -u <Upper Bound for Numbers> -o <Output Filename> -d [Default Values Flag]\n");
		exit(0);
		}
	}
	else {
		printf("Usage: ./makeMatrix -m <Row Amount> -n <Col Amount> -l <Lower Bound for Numbers> -u <Upper Bound for Numbers> -o <Output Filename> -d [Default Values Flag]\n");
		exit(0);
	}
	
	/* CALLING ALL FUNCTIONS NEEDED WITH ERROR CHECKING */
	
	/* Function that mallocs a 2D array*/
	malloc2DArray(&A, rows, cols);
	/* setting the random seed value using the current time */
	srand(time(NULL));
	/* fills the 2D array with random numbers according to inputted parameters */
	fill2DArray(A, rows, cols, upper, lower);
	/* Malloc's and sets values in array for rows/cols ints */
	mallocIntsArray(&C, rows, cols);
	/* writes all data to output file */
	writeToFile(C, A, rows, cols, ofn); 
	
	/* FREE BLOCK */
	free(A);
	free(C);
	
}
