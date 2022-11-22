// to compile: gcc -Wall -o [exicutible name wanted] [location/name of file]
// gcc -Wall -o test ./test.c

// dubugging -g
// gcc -g -Wall -o test ./test.c
// runs debugging within valgrind debugger
// valgrind ./test

#include<stdio.h>
#include<stdlib.h>

int main()	{

	int x = 5;
	// & means the address of
	int* p = &x;
	// the address of the pointer p stored in pp
	int** pp = &p;
	
	// We are printing the value of x and the address of the value of x and the address 	value of p, again &pp means use the address of pp
	printf(" x = %d, p = %p, pp = %p, &pp = %p \n", x, p, pp, &pp);
	
	// Want to change the value of x using p
	
	*p = 10;
	printf(" x = %d, p = %p, pp = %p, &pp = %p \n", x, p, pp, &pp);
	
	// want to change the value of x using pp, 2 stars because you are bypassing 2 pointers 		(pp and p)
	
	**pp = 20;
	printf(" x = %d, p = %p, pp = %p, &pp = %p \n", x, p, pp, &pp);
	
	return 0;
	
}
