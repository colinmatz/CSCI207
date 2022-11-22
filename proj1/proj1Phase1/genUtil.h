/* Colin Matz, Oct 26 2022, CSCI 207, Proj1 - Phase 1 */

int amal(double*** A, int rows, int cols);
int fillmal(double** A, int rows, int cols, double upper, double lower);
int print2D(double** A, int rows, int cols);
double randMake(double upper, double lower);
void printB (double** B, int rows, int cols);
void bmal(double*** B, int rows, int cols);
int retRowsA ();
double ceil(double x);
int fillmal2(double** A, double* B, int rows, int cols);
int malInts(int** A, int rows, int cols);
int writeFile(int* A, double** B, int rows, int cols, char* fN);
int getDat (char* fN, int** A, double** B);
int checksumA(double*** A, int rows, int cols);
int checksumB(double*** A, int rows, int cols);
int multSquare(int R1, double** A, double** B, double** C);
int recSquare(int R1, int R2, int C2, double** res, double** B, double** E);
