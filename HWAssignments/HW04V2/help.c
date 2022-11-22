// Colin Matz
// HW04 Ver. 2
// Sept 29, 2022

#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int a, int b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void swap1(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

// return the sum of a and b 
int foo(int a, int b) {
	int c = a + b;
	return c;
}

// return the sum of the ints that a and b refer to
int foo1(int *a, int *b) {
	int c = *a + *b;
	// printf(" a = %p, b = %p \n", a,b);
	return c;
}

void foo2(int *c, int *a, int *b) {
	*c = *a + *b;
}

/* Requires that "n" be positive.  Returns the sum of the
   first "n" integers. */

int sum (int n) {
  int i;
  int total = 0;
  for (i = 1; i <= n; i++)
    total += i;
  return(total);
}


/* Requires that "n" be positive.  Returns the product of the
   first "n" integers. */

int product (int n) {
	printf("asdfasdfasdf\n");
  int i;
  int total = 1;
  for (i = 1; i <= n; i++)
    total *= i;
  return(total);
}

/* 
	NEW CODE FOR HW03 STARTS HERE
*/

int* read_file(char* fileName, int* numInts) {
	
	// Opens file in read mode using passed in fileName
	FILE *f = fopen(fileName, "r");
	
	// Checks if fopen returned a NULL response and responds according if NULL was assigned
	if(!f) {
		printf("ERROR: Could not locate a file named '%s'! \n", fileName);
		return(NULL);
	}
	// executes code as normal if none of the error conditions are triggered
	else {
		// The next three lines setup and use the stat() function to pull the fileSize of our targeted file
		struct stat st;
		stat(fileName, &st);
		int fileSize = st.st_size;
		
		// this sets the numInts to the number of ints in file by dividing the file size by the size of ints (4)
		*numInts = fileSize / 4;
		
		// if there is no ints that can be pulled from the file, this error condition will trigger and respond accordingly
		if(*numInts<=0){
			printf("ERROR: The file '%s' has no data inside of it! \n", fileName);
			return(NULL);
		}
		// Code continues if error message not triggered
		else {
			// mallocs the array using the file size
			int* A = (int*) malloc(fileSize);
			
			if (A == NULL){
				perror("ERROR: ");
				return(NULL);
			}
			
			// reads and assigns values to the array based on number of ints in file
			int fr = fread(A, sizeof(int), *numInts, f);
			
			if (fr == 0) {
				perror("ERROR: ");
				return(NULL);
			}
			
			// closes file
			fclose(f);
			// returns the array to be assigned in the read_file.c file's array
			return(A);
		}
	}
	
}

void print_array(int* A, int numInts) {
	// checks for NULL value for the array passed in, skips code if value is NULL, executes code if all is good.
	if (A!=NULL) {
		// for loop to print the array
		for (int i=0;i<numInts;i++) {
			// prints each array index and value
			printf("A[%d] = %i\n", i, A[i]);
		}
		
		// before ending, clears the allocated memory as we will be done with this array after this function is ran
		free(A);
	}
	// this code runs if the value of NULL is assigned to the passed in array
	else {
		// error message for the user is printed, no need to return NULL since this is a void function
		printf("ERROR: Cannot print... No elements in array! \n");
	}
}

/* 
	NEW CODE FOR HW03 ENDS HERE
*/

