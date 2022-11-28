/* Colin Matz, Nov 20 2022, CSCI 207, Proj1 - Phase 3 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include "genHelp.h"

void malloc2DArray(int*** A, int rows, int cols){
	// mallocs main 2D array
    int** B = (int **)malloc(sizeof(int *) * rows) + (sizeof(int) * (cols * rows));
	if (!B) {
		perror("malloc2DArray ERROR: ");
		exit(10);
	}
    // ptr is now pointing to the first element in of 2D array
    int* ptr = (int *)(B + rows);
    // for loop to point rows pointer to appropriate location in 2D array
    for(int i = 0; i < rows; i++) {
        B[i] = (ptr + (cols * i));
	}
	// This gives the passed in pointer for A the array by reference (Now pointer A in MAIN points to the array)
    *A = B;
	// No free needed because the passed in pointer from MAIN will point to the 2D array made in this function
	// Therefore no memory is leaked after this program runs :)
    return;  
} 

/* Function creates a random number for each spot in the array and assigns that random value to its position in the array*/
void fill2DArray(int** A, int rows, int cols, int upper, int lower) {
    for(int j=0; j<rows; j++) {
        for(int i=0; i<cols; i++) {
			// the random statement to the right ensures that the random number is within the range specified by user inputs
            A[j][i] = (int) ((rand() % (upper - lower + 1)) + lower);
        }
    }
}
/* function goes through a passed in array and prints each value from the array out to the user */
void print2DArray(int** A, int rows, int cols) {
	int runningTemp = 0; /* Value to track running total of characters read from array */
    for(int j=0; j<rows; j++) {
        for(int i=0; i<cols; i++) {
				int temp = 0; /* variable to track total characters read from each cell in array */
                temp = printf("%d\t", A[j][i]); 
				runningTemp = runningTemp + temp;
        } printf("\n"); /* Creates next line for the next row */
    }
	if (runningTemp == 0) {
		printf("Could not read any data from the array given... Please try another array!\n");
		exit(10); /* Exit value 10 - "ERROR: No readable data in array given!" */
	}
	else {
		return;
	}
} 


/* Function that sums the values and adds them to the new row added to the matrix being checkSum'd 
   Function has no return values */
void checksumA(int*** A, int rows, int cols) {
	/* Creates an array and makes it the passed in array */
	int** C = *A;
	/* If unsuccessful, returns an error */
	if (!C) {
		printf("ERROR: Could not transfer array into checksumA function. Please try again.\n");
		exit(0);
	}
	/* for loop goes through and adds all row values for the current col and then assigns that sum to the checksum cell for that col */
	for(int j=0; j<cols; j++) {
		int sum = 0;
    		for(int i=0; i<rows; i++) {
    			sum = sum + C[i][j];
        	}
        	C[rows][j] = sum;
    	}
    	/* Makes the passed in array the array we created by reference */
    	*A = C;
    	
}

/* Function that sums the values and adds them to the new col added to the matrix being checksum'd 
   Function has no return values */
void checksumB(int*** A, int rows, int cols) {
	/* Creates an array and makes it the passed in array */
	int** C = *A;
	/* If unsuccessful, returns an error */
	if (!C) {
		printf("ERROR: Could not transfer array into checksumB function. Please try again.\n");
		exit(0);
	}
	/* for loop goes through and adds all col values for the current row and then assigns that sum to the checksum cell for that row */
	for(int i=0; i<rows; i++) {
		int sum = 0;
    		for(int j=0; j<cols; j++) {
    			sum = sum + C[i][j];
        	}
        	C[i][cols] = sum;
    	}
    	/* Makes the passed in array the array we created by reference */
    	*A = C;
    	
}
// WORK ON REMOVING THIS AND HAVING GET DATA JUST RETURN THE TWO MALLOCS FROM READING THE FILE --------
/* Function that fills a malloc'd array that fills another array with values from 1st array 
   Function has no return values */
void fill2DArray2(int** A, int* B, int rows, int cols) {
    /* creating local variable count */
    int count = 0;
    /* for loop goes through normal array and assigns values to a 2D array that is passed into the function by reference */
    for(int j=0; j<rows; j++) {
    	for(int i=0; i<cols; i++) {
    		int number = B[count];
        	A[j][i] = number;
        	count++;
        }
    }
    
}

/* Function that writes the int and matrix data into a file MODIFIED!!!!!
   Function has no return values */
void writeToFile(int** B, int rows, int cols, char* fN) {
	
	int* C = malloc(2*sizeof(int));

	if (!C) {
		perror("ERROR ");
		exit(0);
	}

	C[0] = rows;
	C[1] = cols;

	/* first block opens the file in write mode, writes the rows and cols int values and closes the file */
	FILE* f = fopen(fN, "w");
	fwrite(C, sizeof(int), 2, f);
	fclose(f);
	
	/* second block opens the file in append mode (in order to keep previous info added) and writes only the data row by row and closes the file */
	FILE* ff = fopen(fN, "a");
	for (int i = 0; i < rows; i++) {
    		fwrite(B[i], sizeof(int), cols, ff);
	}
	fclose(ff);

	free(C);
	
}

/* Function that gets the row/col data first and puts them in one array, then gets the matrix data and puts that into another array  MODIFIED!!!
   Function has no return values */
void getDataFromFile(char* fN, int** A, int** B){
	/* opens the file in read mode */
	FILE *f = fopen(fN, "r");
	/* checks if file opened and returns error message if not */
	if (!f) {
		perror("ERROR ");
		exit(0);
	}
	/* mallocs a small array to store 2 int values */
	int* G = malloc(2*sizeof(int));
	/* checks if array is malloc'd correctly and prints error if not */
	if (!G) {
		perror("ERROR ");
		exit(0);
	}
	/* reads int from file */
	fread(G, sizeof(int), 2, f);
	/* assigns the values read from the file into the rows and cols values */
	int rows = G[0];
	int cols = G[1];

	/* mallocs an array to hold the data from the file */
	int* H = malloc(rows*cols*sizeof(int));
	/* prints error message if malloc not successful */
	if (!H) {
		perror("ERROR ");
		exit(0);
	}
	/* reads all the actual data from the file using the amount of rows and cols to determine the amount of data cells */
	fread(H, sizeof(int), rows*cols, f);
	/* closes the file */
	fclose(f);
	/* copies the arrays that we made to their respective arrays passed into the function by reference */
	*A = G;
	*B = H;
	
} 

/* Function that takes data from multiple arrays, computes values and stores them in an array for matrices of same size (eg. 2x2 2x2)
   Function has no return values */
void multiplySquareMatrices(int R1, int** A, int** B, int** C) { 
	/* below for loop goes through the array we want to assign values to, and assigns the result of the mathematical equation to multiple the 
	matrices */
	for (int i = 0; i < R1; i++) {
			for (int j = 0; j < R1; j++) {
		    		A[i][j] = 0;
		    		for (int k = 0; k < R1; k++) {
		        		A[i][j] += B[i][k] * C[k][j];
		    		}
			}
	}

}

/* Function that takes data from multiple arrays, computes values and stores them in an array for matrices of different size but still 
	compatable (eg. 2x3 3x2) 
   Function has no return values */
void multiplyRegularMatrices(int R1, int R2, int C2, int** A, int** B, int** C) {
	/* below for loop goes through the array we want to assign values to, and assigns the result of the mathematical equation to multiple the 
	matrices */
	for (int i = 0; i < R1; i++) {
		    for (int j = 0; j < C2; j++) {
		        A[i][j] = 0;
		        for (int k = 0; k < R2; k++) {
		            A[i][j] += B[i][k] * C[k][j];
		        }
		    }
	}

}
/* ------------------------- New Functions for Phase 2  ------------------------- */


/* Function that flips a bit at the desired bit location within a cell detmined by the row/col values passed into function
   Function has no return values */
void corruptArray(int** A, int row, int col, int bitIndex) {
	/* verifies that the bit index passed in is less than 64 and more than 0 or returns error message */
	if (bitIndex > 31 || bitIndex < 0) {
		printf("Error: bitIndex number must be greater than 0 but less than 32!\n");
		exit(0);
	}
	/* subtracts 1 from the user inputted row/col combination to make it a machine indexed value (index starting at 0) */
	int cR = row - 1;
	int cC = col - 1;
	/* Assigns original values to x and a check variable */
	int x = A[cR][cC];
	int check = A[cR][cC];
	/* assigns a pointer to the address of x */
    	unsigned long int *ip = (unsigned long int*)(&x);
	/* flips the bit of the number pointed to by *ip (AKA x) using the bitIndex passed into function */
    	*ip ^= (1UL<<(bitIndex));
    	/* changes the value of the double in the actual array to the new value of x */
    	A[cR][cC] = x;
    	/* checks to ensure the number actually changed and is different than the original, otherwise returns error message */
    	if (A[cR][cC] == check) {
    		printf("ERROR: The matrix was not successfully corrupted, please try again or try new settings for corruption!\n");
    		exit(0);
    	}
    	
}

/* Function that detects if there are errors within the file's cols passed in and reports said errors to a function created file 
   Function has no return values */
void detectColError(int fR, int fC, int** C, int* colErrP) {
	/* alters row value passed in based on whats needed for arithmatic/function processing */
	int cR = fR - 2;
	int ccR = fR - 1;
	/* creating values for checksum cell values and row total values */
	int rowsTot;
	int checksumTot;
	/* creating value for % of percision / % of error in result */
	//double epsilon = 0.0000001f;
	/* for loop to total the values of the rows per col (minus the checksum row) */
	for(int j=0; j<fC; j++) {
		checksumTot = C[ccR][j];
		rowsTot = 0;
		
        	for(int i=0; i<cR+1; i++) {
        		rowsTot = rowsTot + C[i][j];
        	} 
        	/* checks if the values are the same (within the % of error) */
        	if (checksumTot == rowsTot) {
        		/* continues if all is good */
			continue;
        	}
        	/* woah man, theres a problem! Copies the value of the col where error occurs (in human readable notation) and saves it to passed
        	in variable by reference */
        	else {
			*colErrP = j+1;
        	}
        
    	}
    	
}

/* Function that detects if there are errors within the file's rows passed in and reports said errors to a function created file 
   Function has no return values */
void detectRowError(int fR, int fC, int** C, int* rowErrP) {
	/* alters col value passed in based on whats needed for arithmatic/function processing */
	int cC = fC - 2;
	int ccC = fC -1;
	/* creating values for checksum cell values and col total values */
	int colsTot;
	int checksumTot;
	/* creating value for % of percision / % of error in result */
	//double epsilon = 0.0000001f;
	/* for loop to total the values of the cols per row (minus the checksum col) */
	for(int j=0; j<fR; j++) {
		checksumTot = C[j][ccC];
		colsTot = 0;
		
        	for(int i=0; i<cC+1; i++) {
        		colsTot = colsTot + C[j][i];
        	} 
        	/* checks if the values are the same (within the % of error) */
        	if (checksumTot == colsTot) {
        		/* continues if all is good */
        		continue;
        	}
        	/* woah man, theres a problem! Copies the value of the row where error occurs (in human readable notation) and saves it to passed
        	in variable by reference */
        	else {
			*rowErrP = j+1;
        	}
        	
        }
        
}

/* Function that writes the error information to the function created file (row and col values where error was detected) 
   Function has no return values */ 
// PLEASE FOR THE LOVE OF GOD MODULARIZE THIS FUNCTION PLZ OH GOD ITS HORENDOUSLY REDUNDANT
void writeErrorsToFile(int rowErr, int colErr, char* fN2) {
	/* creates variables to hold string values of each value needed to be written in the file */
	char* a = "The row with the error is: ";
        char b[10];
        /* using sprintf to convert the int to a string to be written to the file */
        sprintf(b, "%d\n", rowErr);

        char* c = "The col with the error is: ";
        char d[10];
	/* again, using sprintf to convert the int to a string to be written to the file */
        sprintf(d, "%d\n", colErr);
	/* opens the new file to be made in write mode */
	FILE* f = fopen(fN2, "w");
	/* checks if file open correctly and prints error message if not opened correctly */
	if (!f) {
		perror("ERROR: ");
		exit(0);
	}
	/* writes the first string value to the file */
	fwrite(a, sizeof(char), strlen(a), f);
	fclose(f);
	/* reopens the file in append mode to add next bit of data */
	FILE* ff = fopen(fN2, "a");
	/* checks if the file has been opened correctly */
	if (!ff) {
		perror("ERROR: ");
		exit(0);
	}
	/* writes second string value to file */
	fwrite(b, sizeof(char), strlen(b), ff);
	fclose(ff);
	/* reopens the file in append mode to add next bit of data */
	FILE* fff = fopen(fN2, "a");
	/* checks if the file has been opened correctly */
	if (!fff) {
		exit(0);
	}
	/* writes third string value to file */
	fwrite(c, sizeof(char), strlen(c), fff);
	fclose(fff);
	/* reopens the file in append mode to add next bit of data */
	FILE* ffff = fopen(fN2, "a");
	/* checks if the file has been opened correctly */
	if (!ffff) {
		exit(0);
	}
	/* writes fourth string value to file */	
	fwrite(d, sizeof(char), strlen(d), ffff);
	fclose(ffff);

}

/* Function that finds location of errors, compares row/col totals to checksums and applies the difference of row/col difference from checksums to the
	incorrect number, then writes a new function created file and stores corrected matrix into the file 
   Function has no return values */ 
void findFixErrors(int** C, char* fN, char* fN2, int fR, int fC) {
	/* creating local variables needed */
	int ccR = fR - 1; /* Altering rows amount for machine processing (index starting at 0  not 1) */
	int ccC = fC -1; /* Altering cols amount for machine processing (index starting at 0  not 1) */
	int rowErr = -1; /* initializing row error int number */
	int colErr = -1; /* initialising col error int number */
	int* rowErrP = &rowErr; /* pointer for rowErr */
	int* colErrP = &colErr; /* pointer for colErr */
	//double epsilon = 0.0000001f; /* % of percision / % of error */
	/* runs function to find and assign the col number where the error occurs */
	detectColError(fR, fC, C, colErrP);
	/* runs function to find and assign the row number where the error occurs */
	detectRowError(fR, fC, C, rowErrP);
	/* checks if there is an error detected, if not an error message is printed and program aborted */
	if (rowErr == -1 || colErr == -1) {
		printf("ERROR: Cannot locate any incorrect data values. Did you enter a corrupted file?\n");
		exit(0);
	}
	
	int colChecksumTot = C[ccR][colErr-1]; /* Creates a variable to hold the checksum value for the col where the error occurs */
	int colTot = 0; /* Creates a col total variable */
	
	/* for loop goes through and adds all rows together in the error col and stores in colTot variable */
        for(int i=0; i<ccR; i++) {
        	colTot = colTot + C[i][colErr-1];
        } 
        
        
  int rowChecksumTot = C[rowErr-1][ccC]; /* Creates a variable to hold the checksum value for the row where the error occurs */
	int rowTot = 0; /* Creates a row total variable */
	
	/* for loop goes through and adds all cols together in the error row and stores in rowTot variable */
        for(int i=0; i<ccC; i++) {
        	rowTot = rowTot + C[rowErr-1][i];
        } 
	
	int correctRN1 = colChecksumTot - colTot; /* creates the number needed to be added to the current number to correct based on error col*/
	int correctRN2 = rowChecksumTot - rowTot; /* creates the number needed to be added to the current number to correct based on error row*/
	
	/* checks to ensure that the correction values are the same based on the checksum - totals resulting from calculations in the error row and col */
	/* ensures answer is within % of error determined above */
	if (correctRN1 == correctRN2) {
			/* if so, apply the corrective value to the current value */
        		C[rowErr-1][colErr-1] = C[rowErr-1][colErr-1] + correctRN1;
        	}
        /* checks to ensure than a value of 0 (due to arithmatic error) was not written into the array */
        /* if thats the case, it will print the error message and abort the function */
        if (C[rowErr-1][colErr-1] == 0) {
        		printf("ERROR: Cannot correct corruption in matrix! \n");
        		exit(0);
        	}

}

/* ------------------------- End Of New Functions for Phase 2  ------------------------- */



