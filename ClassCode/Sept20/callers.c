/* Used to illustrate separate compilation.

Created:  Joe Zachary, October 22, 1992
Modified:

*/

#include <stdio.h>
#include "help.h"

int main (int argc, char** argv) {

	// FILE *  fopen(const char * restrict path, const char * restrict mode);
	FILE *f = fopen("bob.dat"   , "w"  );

	int x = 5; // write the 5 into the file,
	//  size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
	int *p = &x;	
	fwrite(p, sizeof(int), 1, f);


	//char* msg = "Hi I like Bob!!!!\n";
	//fputs(msg, f);
	// int fprintf(FILE * restrict stream, const char * restrict format, ...);
	//int x = 5; double y = 5.5;
	//fprintf(f, "x = %d, y = %lf \n", x, y);
		  

	fclose(f);

  return 0;
}
