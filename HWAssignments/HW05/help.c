#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
/* Colin Matz, Oct 16, 2022, CSCI207, HW05 */

/* ---- Beginning of new code for HW05 ---- */

/* following code simply frees the 1D array A */
void free2Dv2(int *A, int rows, int cols){
	free(A);
}

/* below goes into the 1D array based on the rows/cols with the loops and then prints the index using the equation i*cols + j */
void print2Dv2(int *A, int rows, int cols) {
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			printf("%d ", A[i*cols + j]);
		} printf("\n");
	}
}

/* fills the 1D array with numbers 0-11 based on i counter */
void fill2Dv2(int *A, int rows, int cols) {
	for(int i=0; i<(rows*cols); i++){
		A[i] = i;
		
	}
}

/* goes into a loop through the first array of pointers and per pointer frees the array associated with that pointer
 then after all sub-arrays have been free'd, it frees the array of pointers to successfully free the entire 2D array */
void free2Dv1(int **A, int rows, int cols) {
	for (int i=0; i<rows; i++) {
		free(A[i]);
	}
	free(A);
}

/* ---- End of new code for HW05 ---- */

int *malloc2Dv2(int rows, int cols) {
	int *A = malloc(rows*cols*sizeof(int));
	return A;
}


void fill2Dv1(int **A, int rows, int cols) {
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			A[i][j] = i*cols + j;
		}
	}
}

void print2Dv1(int **A, int rows, int cols) {
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			printf("%d ", A[i][j]);
		} printf("\n");
	}
}
	
int **malloc2Dv1(int rows, int cols) {

	/* malloc a block for the row pointers */

	int **A = (int**) malloc(rows*sizeof(int*));
	for(int i = 0; i<rows; i++) {
		A[i] = (int*) malloc(cols*sizeof(int));
	}
	return A;
}

void malloc1D_v2(double **A, int n) {
	double *B = (double*) malloc(n*sizeof(double));
	/* reach  back into mains' SF and set it to addreess B */
	*A = B;
	return;
}
double *malloc1D(int n) {
	double *A = (double*) malloc(n*sizeof(double));
	return A;
}


void malloc2D(double***a , int jmax, int imax)
{
   /* first allocate a block of memory for the row pointers and the 2D array */
   double **x = (double **)malloc(jmax*sizeof(double *) + jmax*imax*sizeof(double));

   /* Now assign the start of the block of memory for the 2D array after the row pointers */
   x[0] = (double *)x + jmax;

   /* Last, assign the memory location to point to for each row pointer */
   for (int j = 1; j < jmax; j++) {
      x[j] = x[j-1] + imax;
   }

    *a = x;
}

void fill2D(double** a, int jmax, int imax) {
    
    int count = 0.0;
    for(int j=0; j<jmax; j++) {
        for(int i=0; i<imax; i++) {
            a[j][i] = count;
            count++;
        }
    }
}

void print2D(double** a, int jmax, int imax) {
    
    for(int j=0; j<jmax; j++) {
        for(int i=0; i<imax; i++) {
            printf("%06.2lf\t", a[j][i]);
        } printf("\n");
    }
}



/* opens file, and reads its contents into an array and returns
	that the contents of that file in that new array.
	It will also set numInts (in the caller's stack frame) to
	the number of integers that were present in the file.
	Any errors opening the file or creating the array should
	be printed to the screen.  On failure, return NULL.
*/
int* read_file(char* fileName, int* numInts) {

	FILE *fd = NULL;
	if(!(fd = fopen(fileName, "r"))) {
		perror("error opening file: ");
		return NULL;
	}
	struct stat buf;
	lstat(fileName, &buf); /* need to check return value */
	int numBytes = (int) buf.st_size;
	*numInts = numBytes / (int) sizeof(int);
	if(*numInts == 0) {
		printf(" file: %s exists, but is either empty or has fewer than %d bytes \n", fileName, (int)sizeof(int));
		/* may need to take some action */
	}	
	int* A = NULL;
  	if(!(A= (int*) malloc(numBytes))) { perror("Error mallocing array "); };
	fread(A, 1, numBytes, fd); /* need to check return value */
	
	fclose(fd); /* need to check return value */

	return A;

}

/* if A is not NULL, it will print the contents of the array A
	to the screen.  If NULL, it will print appropriate error 
	message
*/
void print_array(int* A, int numInts) {
	/* need to check for null here probably  */
	for(int i=0; i< numInts; i++) {
		printf("%d ", A[i]);
	} printf("\n");

	return;
}



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

/* return the sum of a and b */
int foo(int a, int b) {
	int c = a + b;
	return c;
}

/* return the sum of the ints that a and b refer to */
int foo1(int *a, int *b) {
	int c = *a + *b;
	/* printf(" a = %p, b = %p \n", a,b); */
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
