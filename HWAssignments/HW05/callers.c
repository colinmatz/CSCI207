#include <stdio.h>
#include "help.h"

int main (int argc, char** argv) {

	int x = 5;
	int y = 6;
	printf("x = %d y = %d \n", x,y);
	swap1(&x, &y);
	printf("x = %d y = %d \n", x,y);



	/*
	printf(" y = %d, z = %d \n", y,z);
	int x = foo(y, z);
	printf(" y = %d, z = %d \n", y,z);

	printf(" x = % d\n", x);

	x = foo1(&y, &z);
	printf(" y = %d, z = %d \n", y,z);
	
	printf(" x = % d\n", x);
	
	foo2(&x, &y, &z);
	printf(" y = %d, z = %d \n", y,z);
	
	printf(" x = % d\n", x);
	*/
  return 0;
}
