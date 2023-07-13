//Exercise1.4.1.cpp
//Basic C program that asks for text input from the keyboard. 
//The output of this program should be the amount of characters, the amount of words and the amount of newlines that have been typed. 
//Multiple consecutive spaces should not be counted as multiple words.
//
//


// Preprocessor for include files
#include <stdio.h>			// C style I/O
#include <ctype.h>          //This include file declares the narrow character (char) classification functionality.

int main()
{
	int c = 0;  //characters entered by user
	int prev_char = 0;  //previous character entered by user
	int count_chars = 0;  //count of characters
	int count_words = 0;  //count of words
	int count_newlines = 0;  //count of newlines

	//prompt user to enter text
	printf("Enter some text at the prompt:");


	//reading of characters from the keyboard can be stopped when the shutdown-code ^D (CTRL + D) is entered
	//also put in ascii code for CTRL + Z
	while ((c = getchar()) != 4 && c != 26 && c != EOF) 
	{
		if ((isspace(c) == 0) && (isspace(prev_char) || prev_char == 0)) 
		{
			count_words++;
		}
		if (c == 10 || c == 13 || prev_char == 0) 
		{
			count_newlines++;
		}

		count_chars++;
		prev_char = c;
	}

	//Display output
	printf("Amount of characters is: %d \n", count_chars);
	printf("Amount of words is: %d \n", count_words);
	printf("Amount of newlines is: %d \n", count_newlines);

	return 0;
}


