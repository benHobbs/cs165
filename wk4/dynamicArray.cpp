/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/29/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Ex. 7, Problem 2
** 	Filename: dynamicArray.cpp
**
** 	Overview: 	Program asks for length of array, creates said array (dynamically), and asks the
**              the user for the value of each element.  Sorts array and displays high and low
**              value.
**
** 	Input:		Length of Array, Each Array Item (all ints)
**
** 	Output:		low and high value in array
**
**  References: http://www.cplusplus.com/articles/NhA0RXSz/
**
***************************************************************************************************/
#include <iostream>	    //std::cout, std::cin
#include <algorithm>    //sort array

void getValidInput(int &input);

int main()
{
    int len = 0;    //length of dynamic array

    std::cout << "How many elements do you want in your array (int)? ";
    getValidInput(len);     //get length of dynamic array

    int *dynArray = new int[len];   //declare dynamic array

    for ( int i = 0 ; i <= len -1 ; i++ )   //loop for length of dynamic array
    {
        std::cout << "Please enter array element " << i + 1 << " out of " << len << " (int ): ";
        getValidInput(dynArray[i]); //get valid input (int)
    }   //end for loop

    std::sort(dynArray, dynArray + len);    //sort array
    std::cout << "Low Value: " << dynArray[0] << std::endl << "High Value: "
              << dynArray[len - 1] << std::endl;  //print low and high values

    delete [] dynArray;     //clear memory

    return 0;
}

void getValidInput(int &input)      //takes a variable and catches non-valid entries
                                    //cleans up on error and requests new input
{
        while(!(std::cin >> input)) //catches non int entries
        {
            std::cin.clear();       //clear stream
            while(std::cin.get()!= '\n')    //ignores errors before \n escape char
            {
                continue;
            }   //end while loop
            std::cout << "Please enter a valid input: ";
        }   //end while loop
}
