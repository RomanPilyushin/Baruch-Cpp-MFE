//Exercise1.3.5.cpp
//Basic C program that clearly shows the difference between --i and i--.
//
//

// Preprocessor for include files
#include <stdio.h>			// C style I/O
#include <iostream>

int main()
{
	//Demonstrates ++i
	for (int i = 0; i < 10;) 
	{
		printf("Prefix increment: i = %i \n", ++i);
	}

	std::cout << std::endl;

	//Demonstrates i++
	for (int j = 0; j < 10;) 
	{
		printf("Suffix increment: j = %i \n", j++);
	}

	return 0;
}
