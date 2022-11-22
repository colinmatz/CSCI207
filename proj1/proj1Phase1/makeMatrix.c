/* Colin Matz, Oct 26 2022, CSCI 207, Proj1 - Phase 1 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <time.h>
#include "genUtil.h"

int main (int argc, char** argv) {

	/* SETTING INITIAL VALUES */
	int opt;	
	int rows;
	int cols;
	char *ptr;
	double lower;
	double upper;
	char* ofn;
	double** A;
	int* C;
	
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
						lower = strtod(optarg, &ptr);
						break;
					case 'u':
						upper = strtod(optarg, &ptr);
						break;
					case 'o':
						ofn = optarg;
						break;
					case 'd':
						rows = 5;
						cols = 6;
						lower = 0.0;
						upper = 100.0;
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
	
	int c1 = amal(&A, rows, cols);
	
	if (c1 != 1){
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	srand(time(NULL));
	
	int c2 = fillmal(A, rows, cols, upper, lower);
	
	if (c2 != 1) {
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}

	int c3 = malInts(&C, rows, cols);
	
	if (c3 != 1) {
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	int c4 = writeFile(C, A, rows, cols, ofn); 
	
	if (c4 != 1) {
		printf("\nProgram Suspended.. For your safety ;)\n");
		exit(0);
	}
	
	free(A);
	free(C);
	
}
