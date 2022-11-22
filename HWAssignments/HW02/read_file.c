#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int main (int argc, char** argv) {

	// check to see if the right number of parameters were passed
	if(argc!=2) {
		printf("usage: %s <file name to read from> \n", argv[0]);
		exit(1); 
	}

	// FILE *  fopen(const char * restrict path, const char * restrict mode);
	FILE *f = fopen(argv[1]   , "r"  );
	int item;
	// stores temp data required to be read during number of items assessing
	int temp;
	// stores the number of items read from file, -1 due to extra cycle after conditions to stop have been met
	int n = -1;
	int i = 0;
	
	// for loop reads file until it returns 0 from fread, 1 is added to variable n each cycle
	for (int ii=1; ii!=0;){
		ii = fread(&temp, sizeof(int), 1, f);
		n++;
	}
	
	fclose(f);
	
	FILE *ff = fopen(argv[1], "r");
	
	// while loop using n (number of values in file being read) as the condition
	while(n>0) {
		// size_t fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
		i++;
		fread(&item, sizeof(int), 1, ff);
		printf("Item %d from file is = %d \n", i, item);
		// removes 1 from n each cycle to eventually stop when at the end of the values list
		n--;
		
	}
	fclose(ff);
	
	printf("%d \n", temp);

  return 0;
}
