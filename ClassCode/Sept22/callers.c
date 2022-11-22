#include <stdio.h>
#include "help.h"

int main (int argc, char** argv) {

	int y = 5;
	int z = 6;
	
	printf(" y = %d, z = %d \n", y,z);
	int x = foo(y,z);
	
	y = 7;
	z = 8;
	printf("x = %d\n", x);

	x = foo1(&y, &z);
	printf(" y = %d, z = %d \n", y,z);
	printf("x = %d\n", x);
	
	y = 10;
	z = 11;
	foo2(&x, &y, &z);
	printf(" x = %d, y = %d, z = %d \n", x, y, z);

  return 0;
}
