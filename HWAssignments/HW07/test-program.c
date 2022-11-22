/*
Colin Matz
Oct 27, 2022
HW07
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "complex.h"

int main(int argc, char* argv[]) {

	/*CODE PROVIDED FOR ASSIGNMENT*/
	complex_t *c1 = newComplex(3.0, 4.0);
	complex_t *c2 = newComplex(5.0, 6.0);
	printComplex(c1);
	printComplex(c2);
	
	complex_t *c3 = addComplex(c1, c2);
	printComplex(c3);
	
	complex_t *c4 = mulComplex(c1, c2);
	complex_t *c5 = mulComplex(c2, c1); 
	printComplex(c4);
	printComplex(c5);
	
	if(areEqualComplex(c4, c5)) {
		printf("c4 and c5 are the same\n");
	}
	
	/* Added code below to show working checks for areEqualComplex */
	if(!areEqualComplex(c4, c5)) {
		printf("c4 and c5 are not the same\n");
	}
	
	/* added '6.2' to the print statement to round the result number to make more readable */
	printf("abs(c1) = %6.2lf \n", absComplex(c1));	

	/*FREE BLOCK*/
	free(c1);
	free(c2);
	free(c3);
	free(c4);
	free(c5);
	
	return 0;
}
