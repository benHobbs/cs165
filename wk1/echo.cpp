/****************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/13/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Week 1 Assignments/echo program
** 	Filename: echo.cpp
**
** 	Overview: Takes user input and repeats to user.
**
** 	Input: User input (int)
**
** 	Output: Repeats user input to them
**
*****************************************************************/

//Macros
#include <iostream>

int main()
{
	int iUserInput;
	
	std::cout << "\nPlease enter a number (preferably an integer): ";	//Requests an int as input
	
	std::cin >> iUserInput;							//Places user input into int type var iUserInput
	
	std::cout << "You entered the integer " << iUserInput << ".\n\n";	//Prints the users input
	
	return 0;								//Indicates program success
}

