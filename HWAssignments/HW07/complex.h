/*
Colin Matz
Oct 27, 2022
HW07
*/


typedef struct Complex{
    float r;
    float i;
} complex_t;

complex_t* newComplex(double a,double b);
void printComplex(complex_t* a);
complex_t* addComplex(complex_t* a, complex_t* b);
complex_t* mulComplex(complex_t* a, complex_t* b);
int areEqualComplex(complex_t* a, complex_t* b);
double absComplex(complex_t* a);

