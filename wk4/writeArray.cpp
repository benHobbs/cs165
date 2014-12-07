/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/28/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Ex. 6 Problem 1
** 	Filename: writeArray.cpp
**
** 	Overview: 	This program calls a function that takes an int and builds an array of that length.
**              The function makes sure that input is of the correct type, and then sums the value
**              of the array.
**
** 	Input:		Function takes int len (determines # of elements in array
**              User input for each int in array
**
** 	Output:		Sum of all ints in array
**
**  References: http://stackoverflow.com/questions/6408117/using-cin-to-error-handle
**              -explains cin error handling
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin

int getArray(int len); //gets user entry to build an array of len elements, sums values, prints
void getValidInput(int &input);

int main()
{
    int sum = 0, userInput = 0;


	std::cout << "Please enter the length of your array (int): " << std::endl;
	getValidInput(userInput);

    sum = getArray(userInput);    //calls array function (will create a 4 elem array)

    std::cout << "The sum of the elements in your array is: " << sum << std::endl;

    return 0;
}

int getArray(int len)
{
    int iArray[len], sum = 0;   //declare array and sum, init sum to 0

    for ( int i = 0 ; i <= len-1 ; i++ )    //gets each int for array
    {
        std::cout << "Please enter an int value " << (i+1) << " of " << len << ": ";

        while(!(std::cin >> iArray[i])) //catches non int entries
        {
            std::cin.clear();   //clear stream
            while(std::cin.get()!= '\n')    //incase of carraige return
            {
                continue;
            }
            std::cout << "enter a new input: ";
        }

        sum += iArray[i];   //adds new int value to sum
    }

    return sum;
}

void getValidInput(int &input)      //takes a variable and catches non-valid entries
                                    //cleans up on error and requests new input
{
        while(!(std::cin >> input))                         //catches non int entries
        {
            std::cin.clear();               //clear stream
            while(std::cin.get()!= '\n')    //ignores errors before \n escape char
            {
                continue;
            }
            std::cout << "Please enter a valid input: ";
        }
}
