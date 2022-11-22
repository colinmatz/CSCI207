/* Used to illustrate separate compilation

Created:  Joe Zachary, October 22, 1992
Modified:

*/

#include<stdio.h>

void swap(int a, int b) {
	int tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}
// return the sum of a and b
int foo(int a, int b){
	int c = a + b;
	return c;
}
// return the sum of the ints that a and b refer to	
int foo1(int *a, int *b){
	int c = *a + *b;
	//*a = 0;
	//*b = 0;
	//printf("a = %p , b = %p \n", a, b);
	return c;
}

int foo2(int *c, int *a, int *b){
	*c = *a + *b;
	return 0;
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
