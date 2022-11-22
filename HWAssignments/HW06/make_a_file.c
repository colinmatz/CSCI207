#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main (int argc, char** argv) {
	FILE *oF = fopen("a.dat", "w");
	if (!oF) {
		perror("ERROR1 ");
		return 0;
	}
	
	for (int i=0; i<6; i++) {
		int fW = fwrite(&i, sizeof(int), 1, oF);
		printf("current: %d \n", i);
		if (!fW) {
			perror ("ERROR2 ");
			return 0;
		}
	}
	
	int fC = fclose(oF);
	if (!fC) {
		perror ("ERROR3 ");
		return 0;
	}
	
	return 1;
}
