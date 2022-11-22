//hexdump bob.dat prints out what it is in hexidecimal

#include <stdio.h>

int main (int argc, char** argv){
	FILE *f = fopen("bob.dat", "w");
	
	int x = 5; // write the 5 into the file (actual real data)
	int *p = &x; // pointer for x
	
	// fwrite(pointer to the thing you want to write, how big is the item(s), how many items, filename pointer)
	
	fwrite(p, sizeof(int), 1, f);
	
	return 0;
}
