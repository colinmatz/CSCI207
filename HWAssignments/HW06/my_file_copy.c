#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int readFile (char *fName, int* fileSize, int numInts) {
	printf("before open\n");
	printf("%s \n", fName);
	FILE *rF = fopen(fName, "r");
	printf("after open\n");
	if(!rF) {
		perror("ERROR ");
		return 0;
	}
	
	struct stat buf;
	lstat(fName, &buf);
	*fileSize = (int) buf.st_size;
	
	if(*fileSize < 1) {
		printf("Error: This file has no content within it! \n");
		return 0;
	}
	
	printf("this: %d \n", *fileSize / 4);
	numInts = *fileSize / 4;
	printf("this is numInts: %d \n", numInts);
	int* items = malloc(numInts*sizeof(int));
	if (items == 0) {
		printf("Error: Read array cannot be made! \n");
		return 0;
	}
	
	int reF = fread(&items, 1, *fileSize, rF);
	
	if (!reF) {
		perror("ERROR ");
		return 0;
	}
	
	printf("ah1 \n");
	//fclose(rF);
	printf("ah2 \n");
	/*if (!fC) {
		perror("ERROR ");
		return 0;
	} */
	printf("%ls \n", items);
	//int locItems = &items;
	
	return 0;
}

int writeFile (char *fName2, int items, int numInts, int fileSize) {
	printf("ah3 \n");
	FILE *oF = fopen(fName2, "w");
	printf("ah4 \n");
	if (!oF) {
		perror("ERROR ");
		return 0;
	}
	
	int fW = fwrite(&items, fileSize, numInts, oF);
	if (!fW) {
		perror ("ERROR ");
		return 0;
	}
	
	int fC = fclose(oF);
	if (!fC) {
		perror ("ERROR ");
		return 0;
	}
	
	return 1;
}

int main (int argc, char** argv) {
	int fileSize = 0;
	int numInts = 0;

	if (argc < 3) {
		printf("Usage: ./my_file_copy <input file name> <output file name> \n");
		exit(0);
	}
	
	int read = readFile(argv[1], &fileSize, numInts);
	if (read == 0) {
		printf("Error Reading File! \n");
		exit(0);
	}
	printf("after read called \n");
	
	int write = writeFile(argv[2], read, numInts, fileSize);
	if(write == 0) {
		printf("Error Writing New File \n");
		exit(0);
	}
	
	return 0;
}

