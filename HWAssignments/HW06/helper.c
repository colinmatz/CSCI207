#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int readFile (char fName, int* fileSize, int* numInts) {
	FILE *rF = fopen(&fName, "r");
	if(!rF) {
		perror("ERROR ");
		return 0;
	}
	
	printf("popo1 \n");
	int poop = fclose(rF);
	printf("popo2 \n");
	printf("status of close1: %d \n", poop);
	
	struct stat buf;
	lstat(&fName, &buf);
	*fileSize = (int) buf.st_size;
	
	if(*fileSize < 1) {
		printf("Error: This file has no content within it! \n");
		return 0;
	}
	
	printf("this: %d \n", *fileSize / 4);
	*numInts = *fileSize / 4;
	printf("this is numInts: %d \n", *numInts);
	int* items = (int*)malloc(*fileSize);
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
	fclose(rF);
	printf("ah2 \n");
	/*if (!fC) {
		perror("ERROR ");
		return 0;
	} */
	
	return *items;
}

int writeFile (char fName2, int items, int numInts, int fileSize) {
	printf("ah3 \n");
	FILE *oF = fopen(&fName2, "w");
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
