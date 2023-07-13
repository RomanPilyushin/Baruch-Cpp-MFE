//Exercise1.3.8.cpp
//Basic C program that uses assignment-operators.
//Supposed to predict what will be printed on screen (provide a code file with comments stating the output for each line)
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O

int main()
{
	int x = 2;
	int y = 0;
	int z = 0;

	//10
	x *= 3 + 2;
	printf("x = %d\n", x);


	//40
	x *= y = z = 4;
	printf("x = %d\n", x);


	//1
	x = y == z;
	printf("x = %d\n", x);


	return 0;
}
