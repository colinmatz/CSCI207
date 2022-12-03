/* Colin Matz, Nov 20 2022, CSCI 207, Proj1 - Phase 3 */

void malloc2DArray(int*** A, int rows, int cols);
void fill2DArray(int** A, int rows, int cols, int upper, int lower);
void print2DArray(int** A, int rows, int cols);
void writeToFile(int** B, int* rows, int* cols, char* fN);
void getRowsCols (int* rows, int* cols, char* fN);
void getArray(int** A, int rows, int cols, char* fN);
void checksumA(int** A, int rows, int cols);
void checksumB(int** A, int rows, int cols);
void multiplyRegularMatrices(int R1, int R2, int C2, int** A, int** B, int** C);

/* NEW FUNCTION PROTOTYPES FOR PHASE 2 */
void corruptArray(int** A, int row, int col, int bitIndex);
void detectColError(int fR, int fC, int** C, int* colErrP);
void detectRowError(int fR, int fC, int** C, int* rowErrP);
void writeErrorsToFile(int rowErr, int colErr, char* fN2);
void findFixErrors(int** C, char* fN, char* fN2, int fR, int fC);
