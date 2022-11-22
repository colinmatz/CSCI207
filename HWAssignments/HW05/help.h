/* Header file for "help.c"
*/

void fill2Dv1(int **A, int rows, int cols);
void print2Dv1(int **A, int rows, int cols);
int **malloc2Dv1(int rows, int cols);
void free2Dv1(int **A, int rows, int cols);

int *malloc2Dv2(int rows, int cols);
void fill2Dv2(int *A, int rows, int cols);  /* for HW, make these two, and test */
void print2Dv2(int *A, int rows, int cols);	/* test with  valgrind */
void free2Dv2(int *A, int rows, int cols);

double *malloc1D(int n);
void	  malloc1D_v2(double **A, int n);


void malloc2D(double*** a, int jmax, int imax);
void fill2D(double** , int , int );
void print2D(double** a, int jmax, int imax);


/* opens file, and reads its contents into an array and returns
	that the contents of that file in that new array.
	It will also set numInts (in the caller's stack frame) to
	the number of integers that were present in the file.
	Any errors opening the file or creating the array should
	be printed to the screen.  On failure, return NULL.
*/
int* read_file(char* fileName, int* numInts);

/* if A is not NULL, it will print the contents of the array A
	to the screen.  If NULL, it will print appropriate error 
	message
*/
void print_array(int* A, int numInts);

void swap(int a, int b);
void swap1(int *a, int *b);
int foo(int a, int b);
int foo1(int *a, int *b);
void foo2(int *c, int *a, int *b);


int sum (int n);
int product (int n);


