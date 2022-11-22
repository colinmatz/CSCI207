// gcc -Wall -c proj.c
// creates an object file for this specific file
// Need to link all files together now
// gcc -Wall -o runmyproj proj.o foo.o
// default name for a makefile is Makefile -- is a file that interprets like a script
// you can use makefiles to run compiling commands and rm commands
// see file Makefile for structure of said file

#include <stdio.h>
#include "foo.h"

int main(){
	int a=5;
	int b=6;
	int c = foo(a,b);
	printf("%d\n", c);
}
