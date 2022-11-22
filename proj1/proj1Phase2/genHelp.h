/* Colin Matz, Nov 9 2022, CSCI 207, Proj1 - Phase 2 V2 */

void malloc2DArray(double*** A, int rows, int cols);
void fill2DArray(double** A, int rows, int cols, double upper, double lower);
void print2DArray(double** A, int rows, int cols);
void writeToFile(int* A, double** B, int rows, int cols, char* fN);
void getDataFromFile(char* fN, int** A, double** B);
double makeRandNumber(double upper, double lower);
void fill2DArray2(double** A, double* B, int rows, int cols);
void mallocIntsArray(int** A, int rows, int cols);
void checksumA(double*** A, int rows, int cols);
void checksumB(double*** A, int rows, int cols);
void multiplySquareMatrices(int R1, double** A, double** B, double** C);
void multiplyRegularMatrices(int R1, int R2, int C2, double** res, double** B, double** E);

/* NEW FUNCTION PROTOTYPES FOR PHASE 2 */
void corruptArray(double** A, int row, int col, int bitIndex);
void detectColError(int fR, int fC, double** C, int* colErrP);
void detectRowError(int fR, int fC, double** C, int* rowErrP);
void writeErrorsToFile(int rowErr, int colErr, char* fN2);
void findFixErrors(double** C, char* fN, char* fN2, int fR, int fC);
