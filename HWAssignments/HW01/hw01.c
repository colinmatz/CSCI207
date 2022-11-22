// HW01 Assignment
// CSCI 207-01
// Colin Matz
// Sept 4, 2022

// Including the standard libraries as well as the libraries for math (pow) and getopt
#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<math.h>

// main function has argc and argv passed in for the getopt function
int main(int argc, char** argv)	{

	// int variable for getopt function
	int userInput = 0;
	// int variable for user input from getopt
	int inputValue = 0;
	// Initializing array A pointer
	int* A;
	// Initializing b variable
	int b;
	
	// Creating a while loop to run our program within using the getopt function
	while((userInput = getopt(argc, argv, "n:"))){
		// switch allows us to designate different outcomes from the different 	
		//operators added to the command line 
		switch(userInput){
			// case allows us to start writing code for a specific operator from 
			//the command line entry
			case 'n':
				// If there is an extra operator entered, make the entered 
				// value an int
				if (optarg != NULL) {
					inputValue = atoi(optarg);
					}
				// If the user input is zero or below zero an error message will print and the program will end
				if (inputValue < 1) {
					printf("Error: Value %i must be higher than 0! \n", 									inputValue);
					break;
					}
				// If the value of the user input is good, the code will proceed
				else {
				// Dynamic Mem Alloc. using the value entered at command line and the size of int to create space
				A = (int*)malloc(inputValue*sizeof(int));
				// A loop here which will count using i, index that count number, and then use pow() to create the value
				// to store in the index and print said value out for the user
				for (int i = 0; i < inputValue; ++i) {
					// stores pow() function result into the pre-initialized variable b
					int b = pow(2, i);
					// indexes the entry as the count number and then assigns that index the value of b
					A[i] = b;
					printf("A[%d] = %i\n", i, A[i]);
					}
				// frees up the dynamically allocated Mem we set aside earlier in the program
				free(A);
				break;
				}
			// if no case is met, then it will default to just gracefully leaving
			default:
				return 0;
		}
	}
	return 0;
	
}
// this hurt my brain :)
