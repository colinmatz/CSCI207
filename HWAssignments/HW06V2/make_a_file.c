#include <stdlib.h>
#include <stdio.h>

int main (int argc, char** argv) {
	
	FILE *f = fopen("a.dat", "w");
	
	int* A = malloc(10*sizeof(int));
	
	for (int i=0; i<10; i++) {
		A[i] = i;
	}
	
	fwrite(A, 10, sizeof(int), f);
	
	free(A);
	
	fclose(f);
	
	return 1;
}
