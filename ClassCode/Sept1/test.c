// to compile: gcc -Wall -o [exicutible name wanted] [location/name of file]
// gcc -Wall -o test ./test.c

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)	{

	// In an array, '\0' is an ending point for strings
	char C[] = {'a', 'b', 'c', '\0'};
	
	// create array size 100
	int A[100];
	
	// loop where i must stay under 100, but is added to with each loop
	for(int i=0; i<10; i++) {
		// creates array with the size of i and the value of i
		A[i] = i;
		// prints the array and array size
		// %d or %i for int, %c for char, %f for float, and %s for string (Ensure NULL 			terminating charcter for string to show end of string)
		printf("A[%d] = %d \n", i, A[i]);
	}
	
	// malloc allocates size bytes of memory and returns a pointer to the allocated memory
	//int *B = malloc(400); // Never do this!
	//int *B = malloc(numberOfElements*sizeof(datatype)); //this is what you usually want
	
	// creates int for the size
	int N = 10;
	
	// creates dynamically allocated space using N for size
	int *B = malloc(N*sizeof(int)); // this makes 100 int * size of the datatype
	
	// how to store a string in an array and print the string
	char R[] = "Hi my name is Robert!!";
	printf("R = %s \n", R);
	
	// print the array of c in one single string
	printf("C = %s \n", C);
	
	// print each character individually
	for (int i=0; i<3; i++) {
		printf("C[%d] = %c \n", i, C[i]);
	}

	// debugging tools cannot find errors in static allocated mem spaces, but can for 		dynamically allocated mem spaces so use malloc, which you can use weither you know the 		size or not
	
	for(int i=0; i<N; i++) {

		B[i] = i;

		printf("B[%d] = %d \n", i, A[i]);
	}	
	
}
