/* Colin Matz, Nov 20 2022, CSCI 207, Proj1 - Phase 3 */
/* Usable range of exit codes: 78-113 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <time.h>
#include "genHelp.h"

void malloc2DArray(int*** A, int rows, int cols){

	/* ---------------------------------------------- */
	/* mallocs main 2D array */
    int** B = (int **)malloc(sizeof(int *) * rows) + (sizeof(int) * (cols * rows));
	if (!B) {
		perror("malloc2DArray ERROR: ");
		exit(113); /* Exit value 113 - "ERROR: Could not Malloc memory needed with current matrix configuration supplied!" */
	}

	/* ---------------------------------------------- */

    /* ptr is now pointing to the first element in of 2D array */
    int* ptr = (int *)(B + rows);
    /* for loop to point rows pointer to appropriate location in 2D array */
    for(int i = 0; i < rows; i++) {
        B[i] = (ptr + (cols * i));
	}

	/* ---------------------------------------------- */

	/* This gives the passed in pointer for A the array by reference (Now pointer A in MAIN points to the array) */
    *A = B;
	/* No free needed because the passed in pointer from MAIN will point to the 2D array made in this function */
	/* Therefore no memory is leaked after this program runs :) */
    return;  
} 

/* Function creates a random number for each spot in the array and assigns that random value to its position in the array */
void fill2DArray(int** A, int rows, int cols, int upper, int lower) {
    for(int j=0; j<rows; j++) {
        for(int i=0; i<cols; i++) {
			/* the random statement to the right ensures that the random number is within the range specified by user inputs */
            A[j][i] = (int) ((rand() % (upper - lower + 1)) + lower);
        }
    }

	return;
}
// try to seek ahead past the ints and then go directly into the array ****************
void getArray(int** A, int rows, int cols, char* fN) {
	/* ---------------------------------------------- */
    FILE* f = fopen(fN, "r");

	if (!f) {
		perror("File Opening ERROR: ");
		exit(112); /* Exit Value 112 - Can't open file with parameters given! */
	}

	/* ---------------------------------------------- */

	int* ptrR = &rows;
	int* ptrC = &cols;

	int c1 = fread(ptrR, sizeof(int), 1, f);

	if (c1 == 0) {
		printf("ERROR: Cannot get rows value from file given!\n");
		exit(111); /* Exit Value 111 - Can't get rows value from file given!*/
	}

	int c2 = fread(ptrC, sizeof(int), 1, f);

	if (c2 == 0) {
		printf("ERROR: Cannot get cols value from file given!\n");
		exit(110); /* Exit Value 110 - Can't get cols value from file given!*/
	}

	/* ---------------------------------------------- */

	int runTime = 0;
	for(int j=0; j<rows; j++) {
        for(int i=0; i<cols; i++) {
			int* arrayPtr = &A[j][i];
            int temp = fread(arrayPtr, sizeof(int), 1, f);
			runTime = runTime + temp;
        }
    }

	if (runTime == 0) {
		printf("ERROR: Cannot read array elements from file given!\n");
		exit(109); /* Exit Value 109 - Can't read array elements from file given! */
	}

	/* ---------------------------------------------- */

	int c3 = fclose(f);

	if (c3 != 0) {
		perror("File Closing ERROR: ");
		exit(108); /* Exit Value 108 - Error closing file after being read! */
	}

	/* ---------------------------------------------- */

	return;
}

void getRowsCols (int* rows, int* cols, char* fN){

	/* ---------------------------------------------- */

	FILE* f = fopen(fN, "r");

	if (!f) {
		perror("File Opening ERROR: ");
		exit(107); /* Exit Value 107 - Error opening file! */
	}

	/* ---------------------------------------------- */

	int c1 = fread(rows, sizeof(int), 1, f);

	if (c1 == 0) {
		perror("File Row Reading ERROR: ");
		exit(106); /* Exit Value 106 - Error reading rows from file! */
	}

	int c2 = fread(cols, sizeof(int), 1, f);

	if (c2 == 0) {
		perror("File Col Reading ERROR: ");
		exit(105); /* Exit Value 105 - Error reading cols from file! */
	}

	/* ---------------------------------------------- */

	int c3 = fclose(f); 

	if (c3 != 0) {
		perror("File Closing ERROR: ");
		exit(104); /* Exit Value 104 - Error closing file after being read! */
	}

	/* ---------------------------------------------- */

	return;
}

/* function goes through a passed in array and prints each value from the array out to the user */
void print2DArray(int** A, int rows, int cols) {
	/* ---------------------------------------------- */

	int runningTemp = 0; /* Value to track running total of characters read from array */

	/* ---------------------------------------------- */

    for(int j=0; j<rows; j++) {
        for(int i=0; i<cols; i++) {
				int temp = 0; /* variable to track total characters read from each cell in array */
                temp = printf("%d\t", A[j][i]); 
				runningTemp = runningTemp + temp;
        } printf("\n"); /* Creates next line for the next row */
    }
	if (runningTemp == 0) {
		printf("Could not read any data from the array given... Please try another array!\n");
		exit(103); /* Exit value 103 - "ERROR: No readable data in array given!" */
	}

	/* ---------------------------------------------- */

	return;
} 

/* Function that sums the values and adds them to the new row added to the matrix being checkSum'd */
/* Function has no return values */
void checksumA(int** A, int rows, int cols) {

	/* for loop goes through and adds all row values for the current col and then assigns that sum to the checksum cell for that col */
	for(int j=0; j<cols; j++) {
		int sum = 0;
    		for(int i=0; i<rows; i++) {
    			sum = sum + A[i][j];
        	}
        	A[rows][j] = sum;
    	}

	return;
}

/* Function that sums the values and adds them to the new col added to the matrix being checksum'd */
/* Function has no return values */
void checksumB(int** A, int rows, int cols) {

	/* for loop goes through and adds all col values for the current row and then assigns that sum to the checksum cell for that row */
	for(int i=0; i<rows; i++) {
		int sum = 0;
    		for(int j=0; j<cols; j++) {
    			sum = sum + A[i][j];
        	}
        	A[i][cols] = sum;
    	}
    	
	return;
}

/* Function that writes the int and matrix data into a file */
/* Function has no return values */
void writeToFile(int** B, int* rows, int* cols, char* fN) {

	/* ---------------------------------------------- */

	/* first block opens the file in write mode, writes the rows and cols int values and closes the file */
	FILE* f = fopen(fN, "w");

	if (!f) {
		perror("File Opening ERROR: ");
		exit(102); /* Exit Value 102 - Error opening the file! */
	} 

	/* ---------------------------------------------- */

	int c1 = fwrite(rows, sizeof(int), 1, f);

	if (c1 == 0) {
		printf("ERROR: Could not write rows/cols to file! \n");
		exit(101); // Exit Value 101 - Error writing rows/cols to file! 
	}

	int c2 = fwrite(cols, sizeof(int), 1, f);

	if (c2 == 0) {
		printf("ERROR: Could not write rows/cols to file! \n");
		exit(100); // Exit Value 100 - Error writing rows/cols to file! 
	}

	/* ---------------------------------------------- */

	for (int i = 0; i < *rows; i++) {
    		fwrite(B[i], sizeof(int), *cols, f);
	}

	/* ---------------------------------------------- */

	int c3 = fclose(f);

	if (c3 != 0) {
		perror("File Closing ERROR: ");
		exit(99); /* Exit Value 99 - Error closing file after being written! */
	}

	/* ---------------------------------------------- */
	
	return;
}

/* Function that takes data from multiple arrays, computes values and stores them in an array for matrices of same size (eg. 2x2 2x2) */
/* Function has no return values */
void multiplySquareMatrices(int R1, int** A, int** B, int** C) { 
	/* below for loop goes through the array we want to assign values to, and assigns the result of the mathematical equation to multiple the matrices */ 
	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < R1; j++) {
			A[i][j] = 0;
		    for (int k = 0; k < R1; k++) {
				printf("A[%d][%d] = %d, B[%d][%d] = %d, C[%d][%d] = %d\n", i, j, A[i][j], i, k, B[i][k], k, j, C[k][j]);
		        A[i][j] += B[i][k] * C[k][j];
		    }
			if (A[i][j] > 100000 || A[i][j] < -100000) {
				printf("Error: Could not multiply matrices! Please try again or use different parameters.\n");
				exit(98); /* Exit Value 98 - Cannot multiply matrices, could be an arithmetic error. */
			}
		}
	}
	return;
} 

/* Function that takes data from multiple arrays, computes values and stores them in an array for matrices of different size but still compatable (eg. 2x3 3x2) */ 
/* Function has no return values */
void multiplyRegularMatrices(int R1, int R2, int C2, int** A, int** B, int** C) {

	/* below for loop goes through the array we want to assign values to, and assigns the result of the mathematical equation to multiple the 
	matrices */
	for (int i = 0; i < R1; i++) {
		    for (int j = 0; j < C2; j++) {
		        A[i][j] = 0;
		        for (int k = 0; k < R2; k++) {
					printf("A[%d][%d] = %d, B[%d][%d] = %d, C[%d][%d] = %d\n", i, j, A[i][j], i, k, B[i][k], k, j, C[k][j]);
		            A[i][j] += B[i][k] * C[k][j];
		        }
				if (A[i][j] > 100000 || A[i][j] < -100000) {
					printf("Error: Could not multiply matrices! Please try again or use different parameters.\n");
					exit(97); /* Exit Value 97 - Cannot multiply matrices, could be an arithmetic error. */
				}
		    }
	}

}

/* Function that flips a bit at the desired bit location within a cell determined by the row/col values passed into function function has no return values */
void corruptArray(int** A, int row, int col, int bitIndex) {

	/* ---------------------------------------------- */

	/* verifies that the bit index passed in is less than 64 and more than 0 or returns error message */
	if (bitIndex > 31 || bitIndex < 0) {
		printf("Error: bitIndex number must be greater than 0 but less than 32!\n");
		exit(96); /* Exit Value 96 - bitIndex value invalid! */
	}

	/* ---------------------------------------------- */

	/* subtracts 1 from the user inputted row/col combination to make it a machine indexed value (index starting at 0) */
	int cR = row - 1;
	int cC = col - 1;
	/* Assigns original values to x and a check variable */
	int x = A[cR][cC];
	int check = A[cR][cC];
	/* assigns a pointer to the address of x */
    unsigned long int *ip = (unsigned long int*)(&x);

	/* ---------------------------------------------- */

	/* flips the bit of the number pointed to by *ip (AKA x) using the bitIndex passed into function */
    *ip ^= (1UL<<(bitIndex));

	/* ---------------------------------------------- */

    /* changes the value of the double in the actual array to the new value of x */
    A[cR][cC] = x;
    /* checks to ensure the number actually changed and is different than the original, otherwise returns error message */
    if (A[cR][cC] == check) {
    	printf("ERROR: The matrix was not successfully corrupted, please try again or try new settings for corruption!\n");
    	exit(95); /* Exit Value 95 - Matrix was not successfully corrupted! */
    }

    return;
}

/* Function that detects if there are errors within the file's cols passed in and reports said errors to a function created file function has no return values */
void detectColError(int fR, int fC, int** C, int* colErrP) {

	/* ---------------------------------------------- */

	/* alters row value passed in based on whats needed for arithmetic/function processing */
	int cR = fR - 2;
	int ccR = fR - 1;
	/* creating values for checksum cell values and row total values */
	int rowsTot;
	int checksumTot;

	/* ---------------------------------------------- */

	/* for loop to total the values of the rows per col (minus the checksum row) */
	for(int j=0; j<fC; j++) {
		checksumTot = C[ccR][j];
		rowsTot = 0;
		
        for(int i=0; i<cR+1; i++) {
        	rowsTot = rowsTot + C[i][j];
        } 
        /* checks if the values are the same */
        if (checksumTot == rowsTot) {
        	/* continues if all is good */
			continue;
        }
        /* woah man, theres a problem! Copies the value of the col where error occurs (in human readable notation) and saves it to passed in variable by reference */
        else {
			*colErrP = j+1;
        }
        
    }
    
	return;
}

/* Function that detects if there are errors within the file's rows passed in and reports said errors to a function created file function has no return values */
void detectRowError(int fR, int fC, int** C, int* rowErrP) {

	/* ---------------------------------------------- */

	/* alters col value passed in based on whats needed for arithmetic/function processing */
	int cC = fC - 2;
	int ccC = fC -1;
	/* creating values for checksum cell values and col total values */
	int colsTot;
	int checksumTot;

	/* ---------------------------------------------- */

	/* for loop to total the values of the cols per row (minus the checksum col) */
	for(int j=0; j<fR; j++) {
		checksumTot = C[j][ccC];
		colsTot = 0;
		
        for(int i=0; i<cC+1; i++) {
        	colsTot = colsTot + C[j][i];
        } 
        /* checks if the values are the same */
        if (checksumTot == colsTot) {
        	/* continues if all is good */
        	continue;
        }
        /* woah man, theres a problem! Copies the value of the row where error occurs (in human readable notation) and saves it to passed in variable by reference */
        else {
		*rowErrP = j+1;
        }
        	
    }
    return; 
}

/* Function that writes the error information to the function created file (row and col values where error was detected) function has no return values */ 
void writeErrorsToFile(int rowErr, int colErr, char* fN2) {

	/* ---------------------------------------------- */

	/* creates variables to hold string values of each value needed to be written in the file */
	char* a = "The row with the error is: ";
    char b[10];
    /* using sprintf to convert the int to a string to be written to the file */
    int c1 = sprintf(b, "%d\n", rowErr);

	if (c1 == 0){
		printf("ERROR: Could not format row int error value for file writing!\n");
		exit(94); /* Exit Value 94 - Could not format row int error value */
	}

    char* c = "The col with the error is: ";
    char d[10];
	/* again, using sprintf to convert the int to a string to be written to the file */
    int c2 = sprintf(d, "%d\n", colErr);

	if (c2 == 0){
		printf("ERROR: Could not format col int error value for file writing!\n");
		exit(93); /* Exit Value 93 - Could not format col int error value */
	}

	/* ---------------------------------------------- */

	/* opens the new file to be made in write mode */
	FILE* f = fopen(fN2, "w");
	/* checks if file open correctly and prints error message if not opened correctly */
	if (!f) {
		perror("ERROR: ");
		exit(92); /* Exit Value 92 - Could not open file! */
	}

	/* writes the first string value to the file */
	int c3 = fwrite(a, sizeof(char), strlen(a), f);

	if (c3 == 0) {
		printf("ERROR: Could not write data to file! \n");
		exit(91); /* Exit Value 91 - Error writing row beginning string to file! */
	}

	int c4 = fwrite(b, sizeof(char), strlen(b), f);

	if (c4 == 0) {
		printf("ERROR: Could not write data to file! \n");
		exit(90); /* Exit Value 90 - Error writing row error data to file! */
	}

	int c5 = fwrite(c, sizeof(char), strlen(c), f);

	if (c5 == 0) {
		printf("ERROR: Could not write data to file! \n");
		exit(89); /* Exit Value 89 - Error writing col beginning string to file! */
	}

	int c6 = fwrite(d, sizeof(char), strlen(d), f);

	if (c6 == 0) {
		printf("ERROR: Could not write data to file! \n");
		exit(88); /* Exit Value 88 - Error writing col error data to file! */
	}

	int c7 = fclose(f);

	if (c7 != 0) {
		perror("File Closing ERROR: ");
		exit(87); /* Exit Value 87 - Error closing file after being written! */
	}

	/* ---------------------------------------------- */

	return;
}

/* Function that finds location of errors, compares row/col totals to checksums and applies the difference of row/col difference from checksums to the incorrect number, then writes a new function created file and stores corrected matrix into the file */
/* Function has no return values */ 
void findFixErrors(int** C, char* fN, char* fN2, int fR, int fC) {

	/* ---------------------------------------------- */

	/* creating local variables needed */
	int ccR = fR - 1; /* Altering rows amount for machine processing (index starting at 0  not 1) */
	int ccC = fC -1; /* Altering cols amount for machine processing (index starting at 0  not 1) */
	int rowErr = -1; /* initializing row error int number */
	int colErr = -1; /* initialising col error int number */
	int* rowErrP = &rowErr; /* pointer for rowErr */
	int* colErrP = &colErr; /* pointer for colErr */

	/* ---------------------------------------------- */

	/* runs function to find and assign the col number where the error occurs */
	detectColError(fR, fC, C, colErrP);
	/* runs function to find and assign the row number where the error occurs */
	detectRowError(fR, fC, C, rowErrP);

	/* checks if there is an error detected, if not an error message is printed and program aborted */
	if (rowErr == -1 || colErr == -1) {
		printf("ERROR: Cannot locate any incorrect data values. Did you enter a corrupted file?\n");
		exit(86); /* Exit Value 86 - Could not find any corrupted data values! */
	}

	/* ---------------------------------------------- */
	
	int colChecksumTot = C[ccR][colErr-1]; /* Creates a variable to hold the checksum value for the col where the error occurs */
	int colTot = 0; /* Creates a col total variable */
	
	/* for loop goes through and adds all rows together in the error col and stores in colTot variable */
    for(int i=0; i<ccR; i++) {
        colTot = colTot + C[i][colErr-1];
    } 
        
	/* ---------------------------------------------- */
        
  	int rowChecksumTot = C[rowErr-1][ccC]; /* Creates a variable to hold the checksum value for the row where the error occurs */
	int rowTot = 0; /* Creates a row total variable */
	
	/* for loop goes through and adds all cols together in the error row and stores in rowTot variable */
    for(int i=0; i<ccC; i++) {
        rowTot = rowTot + C[rowErr-1][i];
    } 

	/* ---------------------------------------------- */
	
	int correctRN1 = colChecksumTot - colTot; /* creates the number needed to be added to the current number to correct based on error col*/
	int correctRN2 = rowChecksumTot - rowTot; /* creates the number needed to be added to the current number to correct based on error row*/
	
	/* checks to ensure that the correction values are the same based on the checksum - totals resulting from calculations in the error row and col */
	if (correctRN1 == correctRN2) {
		/* if so, apply the corrective value to the current value */
        C[rowErr-1][colErr-1] = C[rowErr-1][colErr-1] + correctRN1;
    }

    /* checks to ensure than a value of 0 (due to arithmetic error) was not written into the array. If thats the case, it will print the error message and abort the function */
    if (C[rowErr-1][colErr-1] == 0) {
        printf("ERROR: Cannot correct corruption in matrix! \n");
        exit(85); /* Exit Value 85 - Could not correct corrupted value in matrix! */
    }

	return;
}
