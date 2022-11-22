#include <stdio.h>

int main (int argc, char** argv){
	// FILE * fopen(filename, open mode)
	// w mode overwrites entire file and can create a file if not there
	// a mode just adds to a file
	// r mode reads the file
	// adding + makes it for reading and writing
	FILE *f = fopen("bob", "w");
	
	char* msg = "Hi, I like bob!!!\n";
	
	// fputs(string want to put in file, file to edit)
	fputs(msg, f);
	// int fprintf(file want to edit, string and variables as normal printf statement)
	int x = 5;
	double y = 5.5;
	fprintf(f, "x = %d, y = %lf \n", x, y);
	
	// fclose(file want to close)
	fclose(f);
	return 0;
}
