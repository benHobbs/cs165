/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/28/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Ex. 6 Problem 2
** 	Filename: cStrCompare.cpp
**
** 	Overview: 	This functions accepts two references to c-strings and returns whether they have
**              the same values.
**
** 	Input:      2 c-strings (by reference)
**
** 	Output:		bool
**
**  References: http://www.cplusplus.com/reference/cstring/strlen/
**              -string h (strlen())
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin
#include <string.h> //strlen

bool cStrCompare(char cStr1[], char cStr2[]);

int main()
{
    char cStr1[21];
    char cStr2[21];

    std::cout << "Please enter your first string (<20 chars): ";
    std::cin.getline(cStr1,20);

    std::cout << "Please enter your second string (<20 chars): ";
    std::cin.getline(cStr2,20);

    std::cout << cStrCompare(cStr1,cStr2) << std::endl << "If you are confused about this output "
	      << "please read the program header." << std::endl;
}

bool cStrCompare(char cStr1[], char cStr2[])
{
    if ( strlen(cStr1) != strlen(cStr2) )   //if the 2 cstrings are different sizes, return false
    {
        return false;
    }
    else
    {
        for (int i = 0 ; i <= strlen(cStr1) ; i++)
        {
            if ( cStr1[i] != cStr2[i] )
            {
                return false;
            }
        }
        return true;
    }
}
