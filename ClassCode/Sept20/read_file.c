#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int main(int argc, char** argv) {

	// check to see if right number of parameters were passed
	if(argc!=2) {
		printf("usage: %s <file name to read from> \n", argv[0]);
	}
	// FILE * fopen(const char * restrict path, const char * restrict mode);
	FILE *f = fopen(argv[1], "r");
	
	int item;
	
	for(int i=0; i<5; i++){
	
	//fread (Where do you want to put the info, sizeof , how many items , where you want to read
	
		fread(&item, sizeof(int), 1, f);
		
		printf("Item %d from file is = %d\n", i, item);
	
	}
	
	fclose(f);

	return 0;	
}
