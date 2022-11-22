/* included make_a_file program to help make specific sized files to test */
/*
Colin Matz
Oct 19, 2022
HW06 V2
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
	/* Determines if correct amount of arguments met */
	if (argc !=3) {
		printf("usage: ./my_file_copy <input filename> <output filename>");
		exit(0);
	}
	
	FILE *f = fopen(argv[1], "r"); 
	
	if (!f) {
		perror("ERROR ");
		exit (0);
	}
	
	/* gets file info/size */
	struct stat buf;
	stat(argv[1], &buf);
	int fileSize = buf.st_size; 
	
	if (fileSize == 0) {
		printf("ERROR: No data in file \n");
		exit (0);
	}
	
	int numInts = fileSize / 4;
	
	/* creates array for values to be read into */
	
	int* B = malloc(numInts*sizeof(int));
	
	if (!B) {
		perror("ERROR ");
		exit (0);
	}
	
	/* reads values from file into made array */
	
	int fR = fread(B, sizeof(int), numInts, f);
	
	if (fR != numInts) {
		perror("ERROR ");
		exit (0);
	}
	
	int fC = fclose(f); 
	
	 if (fC != 0) {
		perror("ERROR ");
		exit (0);
	} 
	
	/* ----- */
	
	/* opens new file in w since it probably doesn't exsist or overwrite if does */
	
	FILE *ff = fopen(argv[2], "w");
	
	if(!ff) {
		perror("ERROR ");
		exit(0);
	}
	
	/* writes array B into file */
	fwrite(B, numInts, sizeof(int), ff);

	
	int ffC = fclose(ff); 
	
	 if (ffC != 0) {
		perror("ERROR ");
		exit(0);
	} 
	
	free(B);
	
	exit(0);
	
}
