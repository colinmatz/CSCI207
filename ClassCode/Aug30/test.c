// to compile: gcc -Wall -o [exicutible name wanted] [location/name of file]
// gcc -Wall -o test ./test.c

#include<stdio.h>
#include<stdlib.h>

int main()	{

	int x = 5;
	// & means the address of
	int* p = &x;
	
	
	// prints the size of an int, %zu to match type of int
	printf("size of an int = %zu \n", sizeof(int));
	// prints the size of a pointer, %zu to match type of int
	printf("size of an int = %zu \n", sizeof(int*));
	
	// We are printing the value of x and the address of the value of x
	printf(" x = %d, p = %p \n", x, p);
	
	// Easily change the value of x this way
	x = 10;
	
	printf(" x = %d, p = %p \n", x, p);
	
	// If you wanted to change x via p, doing p = 20 changes the address stored in p to 20 		not changing x
	
	
	// the star means go to the place that p points to and change that value to 20
	*p = 20;
	
	printf(" x = %d, p = %p \n", x, p);
	
	// creates a pointer to the location of the data of p
	int** pp = &p;
	
	// creates a pointer to the location of the data of pp
	int*** ppp = &pp;
	
	return 0;
	
}
