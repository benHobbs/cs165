/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/28/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Ex. 7 Problem 1
** 	Filename: pointer_1.cpp
**
** 	Overview: 	This program creates an int and a pointer to said int.  Passes pointer to function
**              where user is prompted to enter a number.  This number is assigned to the address
**              of the referenced int and then output in main.
**
** 	Input:		Int
**
** 	Output:		Pointer reference to entered int
**
**  References: Not the book
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin

void pointer(int* pointer);

int main()
{
    int v1 = 0, *p1;    //declare int and pointer
    p1 = &v1;           //set address for pointer

    pointer(p1);        //pass pointer to function

    std::cout << "Value: " << v1 << std::endl; //output int

    return 0;
}

void pointer(int* p1)
{
    std::cout << "Please enter an integer: ";   //prompt for new value
    std::cin >> *p1;                            //replace value at address with new value
}

