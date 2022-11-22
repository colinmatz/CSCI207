// Colin Matz
// HW04 Ver. 2
// Sept 29, 2022

/* Header file for "help.c"
*/

int sum (int n);
int product (int n);

int foo(int, int);
int foo1(int *, int *);
void foo2(int*, int *, int *);
void swap(int a, int b);
void swap1(int *a, int *b);

// NEW CODE FOR HW03

int* read_file(char* fileName, int* numInts);

void print_array(int* A, int numInts);
void perror(const char *str);

