/*
Colin Matz
Oct 27, 2022
HW07
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "complex.h"
#define M_PI 3.141592654

char* format = "rect";
char* angle = "deg";

complex_t* newComplex(double a, double b) {
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
	if (strcmp(format, "rect") == 0) {
		if (a->i >= 0) {
    			printf("Result: %6.2lf + %6.2lfi\n", a->r, a->i);
    		}
    		if (a->i < 0) {
    			printf("Result: %6.2lf - %6.2lfi\n", a->r, a->i*-1);
    		}
    	}
    	if (strcmp(format, "pol") == 0) {
    		if (strcmp(angle, "deg") == 0){ 
    			char* degs="\u00B0";
    			double m = sqrt(pow(a->r, 2)+pow(a->i, 2));
    			double omg = atan(a->i/a->r);
    			double d = (omg * 180) / M_PI;
    			printf("Result: %6.2lf < %6.2lf%s\n", m, d, degs);
    		}
    		if (strcmp(angle, "rad") == 0) {
    			double m = sqrt(pow(a->r, 2)+pow(a->i, 2));
    			double omg = atan(a->i/a->r);
    			printf("Result: %6.2lf < %6.2lf in radians\n", m, omg);
    		}
    	}
}

complex_t* addComplex(complex_t* a, complex_t* b){	
	/* assigns new values to structure variables */
	double tr = a->r + b->r;
	double ti = a->i + b->i;
	
	/* returns the structure to the pointer in main*/
	return newComplex(tr, ti);
}

complex_t* mulComplex(complex_t* a, complex_t* b){	
	/* assigns new values to structure variables */
	double tr = a->r * b->r - a->i * b->i;
	double ti = a->r * b->i + a->i * b->r;
	
	/* returns the structure to the pointer in main*/
	return newComplex(tr, ti);
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

/* NEW CODE HW08 */

void setFormatPolar(){
	format = "pol";
}

void setAngleRad(){
	angle = "rad";
}

void setFormatRect(){
	format = "rect";
}

void setAngleDeg(){
	angle = "deg";
}

complex_t* conjugateComplex(complex_t *a){
	double i = a->i * -1;
	double r = a->r;
	return newComplex(r, i);
}

complex_t* divComplex(complex_t *a, complex_t *b){
	double i = a->i;
	double r = a->r;
	double ii = b->i;
	double rr = b->r;
	
	double dr = (r * rr + i * ii) / (rr * rr + ii * ii);
	double di = (i * rr - r * ii) / (rr * rr + ii * ii);
	
	return newComplex(dr, di);
}


