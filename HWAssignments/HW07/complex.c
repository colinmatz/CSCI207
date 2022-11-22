/*
Colin Matz
Oct 27, 2022
HW07
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "complex.h"


complex_t* newComplex(double a,double b) {
	/* Mallocs space for the structure */
	complex_t* t = malloc(sizeof(complex_t));
	/* Checks if malloc was successfull */
	if (!t) {
		exit(0);
	}
	
	/* assigns values to structure variables */
	t->r = a;
	t->i = b;
	
	/* returns the structure to the pointer in main*/
	return t;
}

void printComplex(complex_t* a){
    	printf("Result: %6.2lf + %6.2lfi\n", a->r, a->i);
}

complex_t* addComplex(complex_t* a, complex_t* b){
	/* Mallocs space for the structure */
	complex_t* t = malloc(sizeof(complex_t));
	/* Checks if malloc was successfull */
	if (!t) {
		exit(0);
	}
	
	/* assigns new values to structure variables */
	t->r = a->r + b->r;
	t->i = a->i + b->i;
	
	/* returns the structure to the pointer in main*/
	return t;
}

complex_t* mulComplex(complex_t* a, complex_t* b){
	/* Mallocs space for the structure */
	complex_t* t = malloc(sizeof(complex_t));
	/* Checks if malloc was successfull */
	if (!t) {
		exit(0);
	}
	
	/* assigns new values to structure variables */
	t->r = a->r * b->r - a->i * b->i;
	t->i = a->r * b->i + a->i * b->r;
	
	/* returns the structure to the pointer in main*/
	return t;
}

int areEqualComplex(complex_t* a, complex_t* b) {
	/* Checks if the two real values are the same */
	if (a->r == b->r) {
		/* Checks if the two imaginary values are the same */
		if (a->i == b->i) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

double absComplex(complex_t* a) {
	/* returns the square root of the numbers in the complex structure passed in*/
	return sqrt(a->r * a->r + a->i * a->i);
}

