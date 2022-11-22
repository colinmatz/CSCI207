#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	printf("argc = %d \n", argc);
	
	for (int i=0; i<argc; i++) {
		printf("argv[%d] = %s \n", i, argv[i]);
	}
	
	// Read man page for getopt

	long int n = atol(argv[1]);
	printf("addr = %p\n", argv[1]);
	printf("n = %ld\n", n);
	
	int* a = malloc(sizeof(int)*n);
	
	if(a==NULL){
		printf("There is a major problem!!\n");
		exit(1);
	}
	else {
		printf("All ok! :)\n");
	}
	
	for (long int i=0; i<n; i++) {
		a[i] - i;
	}

	free(a);

	return 0;
}
