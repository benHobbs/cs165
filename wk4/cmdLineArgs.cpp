/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 2/1/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Ex. 7 Problem 5
** 	Filename: pointer_cmdLineArg.cpp
**
** 	Overview: 	This program creates an int and a pointer to said int.  Takes command line argument
**              and sets equal to pointer.  Passes pointer to function where value is doubled.
**
** 	Input:		Int (command line arg)
**
** 	Output:		Pointer reference to entered int
**
**  References: http://www.cplusplus.com/articles/DEN36Up4/
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin
#include <stdlib.h> //atoi

void pointer(int* pointer);

int main(int argc, char* argv[])
{
    if (argc > 1)	//catch no args
    {
   	 int v1 = 0, *p1;    //declare int and pointer
   	 p1 = &v1;           //set address for pointer

    	*p1 = atoi(argv[1]);

   	 pointer(p1);        //pass pointer to function

    	std::cout << "Value: " << v1 << std::endl; //output int
    }
    else
    {
	std::cout << "Please enter an argument of type int.  This program will double the int.\n";
    }
    return 0;
}

void pointer(int* p1)
{
    *p1 *= 2;   //doubles
}
