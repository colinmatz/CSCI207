/* Colin Matz, Oct 26 2022, CSCI 207, Proj1 - Phase 1 */

#include <stdlib.h>
#include <stdio.h>
#include "genUtil.h"

/* Function that creates a 2D array using a passed in array, rows and cols */
int amal(double*** A, int rows, int cols){
   
	double **B = (double **)malloc(rows*sizeof(double *) + rows*cols*sizeof(double));
   
   	if (!B) {
   		perror("ERROR ");
		return 0;
   	}

   	B[0] = (double *)B + rows;

   	for (int i = 1; i < rows; i++) {
   		B[i] = B[i-1] + cols;
   	}

   	*A = B;
    
   	return 1;
} 

/* Function that creates and returns random numbers based on upper and lower passed in */
double randMake(double upper, double lower) {
	double ran = ((double) rand()) / RAND_MAX;	
	double ranRange = (upper - lower) * ran;
	double number = lower + ranRange;	
	return number;
}

/* Function that fills a malloced array of randomly generated numbers */
int fillmal(double** A, int rows, int cols, double upper, double lower) {
    
    for(int j=0; j<rows; j++) {
    	for(int i=0; i<cols; i++) {
        	double number = randMake(upper, lower);
        	A[j][i] = number;
        }
    }
    
    return 1;
}

/* Function that sums the values and addes them to the new row added to the matrix being checkSum'd */
int checksumA(double*** A, int rows, int cols) {
	double** C = *A;
	
	if (!C) {
		perror("ERROR ");
		return 0;
	}
	
	for(int j=0; j<cols; j++) {
		double sum = 0;
    		for(int i=0; i<rows; i++) {
    			sum = sum + C[i][j];
        	}
        	C[rows][j] = sum;
    	}
    	
    	*A = C;
    	
    	return 1;
}

/* Function that sums the values and adds them to the new col added to the matrix being checksum'd */
int checksumB(double*** A, int rows, int cols) {
	double** C = *A;
	
	if (!C) {
		perror("ERROR ");
		return 0;
	}
	
	for(int i=0; i<rows; i++) {
		double sum = 0;
    		for(int j=0; j<cols; j++) {
    			sum = sum + C[i][j];
        	}
        	C[i][cols] = sum;
    	}
    	
    	*A = C;
    	
    	return 1;
}

/* Function that fills a malloc'd array that fills another array with values from 1st array */
int fillmal2(double** A, double* B, int rows, int cols) {
    int count = 0;
    for(int j=0; j<rows; j++) {
    	for(int i=0; i<cols; i++) {
    		double number = B[count];
        	A[j][i] = number;
        	count++;
        }
    }
    
    return 1;
}

/* Function that goes through an array and prints out the data per cell */
int print2D(double** A, int rows, int cols) {
    
    for(int j=0; j<rows; j++) {
        for(int i=0; i<cols; i++) {
            printf("%06.2lf\t", A[j][i]);
        } printf("\n");
    }
    
    return 1;
} 

/* mallocs a small array to store row and col ints for file writing */
int malInts(int** A, int rows, int cols) {
	int* B = malloc(2*sizeof(int));
	
	if (!B) {
		perror("ERROR ");
		return 0;
	}
	
	B[0] = rows;
	B[1] = cols; 
	
	*A = B;
	
	return 1;
}

/* Function that writes the int and matrix data into a file */
int writeFile(int* A, double** B, int rows, int cols, char* fN) {

	FILE* f = fopen(fN, "w");
	fwrite(A, sizeof(int), 2, f);
	fclose(f);
	
	FILE* ff = fopen(fN, "a");
	fwrite(B, sizeof(double), rows+rows*cols, ff);
	fclose(ff);
	
	return 1;
}

/* Function that gets the row/col data first and puts them in one array, then gets the matrix data and puts that into another array */
int getDat (char* fN, int** A, double** B){
	FILE *f = fopen(fN, "r");
	
	int* G = malloc(2*sizeof(int));
	if (!G) {
		perror("ERROR ");
		return 0;
	}
	fread(G, sizeof(int), 2, f);
	
	int rows = G[0];
	int cols = G[1];
	
	double* H = malloc(rows+rows*cols*sizeof(double));
	if (!H) {
		perror("ERROR ");
		return 0;
	}
	fseek(f, rows*sizeof(double), SEEK_CUR);
	fread(H, sizeof(double), rows+rows*cols, f);
	
	fclose(f);
	
	*A = G;
	*B = H;
	
	return 1;
} 
/* Function that takes data from multiple arrays, computes values and stores them in an array for matrices of same size (eg. 2x2 2x2)*/
int multSquare(int R1, double** A, double** B, double** C) { 
	for (int i = 0; i < R1; i++) {
			for (int j = 0; j < R1; j++) {
		    		A[i][j] = 0;
		    		for (int k = 0; k < R1; k++) {
		        		A[i][j] += B[i][k] * C[k][j];
		    		}
			}
	}
	return 1;
}

/* Function that takes data from multiple arrays, computes values and stores them in an array for matrices of different size but still 
compatable (eg. 2x3 3x2) */
int recSquare(int R1, int R2, int C2, double** A, double** B, double** C) {
	for (int i = 0; i < R1; i++) {
		    for (int j = 0; j < C2; j++) {
		        A[i][j] = 0;
		        for (int k = 0; k < R2; k++) {
		            A[i][j] += B[i][k] * C[k][j];
		        }
		    }
	}
	return 1;
}
