#include <stdio.h>
#include <stdlib.h>
#include "help.h"

/* example for 2D arrays */

int main(int argc, char* argv[]) {
	int rows = 3; int cols = 4;
	int **Av1 = malloc2Dv1(rows,cols);
	fill2Dv1(Av1, rows, cols);
	print2Dv1(Av1, rows, cols);
	free2Dv1(Av1, rows, cols);  /* you need to implement this DONE */
	
	printf("\n ----- \n\n");

	int *Av2 = malloc2Dv2(rows, cols);
	fill2Dv2(Av2, rows, cols);   /* you need to implement this DONE */
	print2Dv2(Av2, rows, cols);  /* you need to implement this DONE */
	free2Dv2(Av2, rows, cols);   /* you need to implement this DONE */

	return 0;

/*
	if(argc!=3) {
		printf("usage: %s <rows> <cols> \n", argv[0]);
		exit(1);
	}
*/
	
/*
	double *WMJ = malloc1D(100);
	for(int i=0; i<100; i++) {
		WMJ[i] = 1.0;
	}

	free(WMJ);
	
	double *WMJv2;
	malloc1D_v2(&WMJv2, 100);

	for(int i=0; i<100; i++) {
		WMJv2[i] = 1.0;
	}

	free(WMJ);
*/

	/* example 2D array */
	rows = atoi(argv[1]);
	cols = atoi(argv[2]);
	double **A;
	malloc2D(&A, rows, cols);
	fill2D(A, rows, cols);
	print2D(A, rows, cols);

	
	return 0;
}
