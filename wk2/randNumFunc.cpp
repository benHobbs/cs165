/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/18/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Excercise 4 Problem 1
** 	Filename: randNumFunc.cpp
**
** 	Overview: 	This program uses a function to return a random number between two user specified
**              values.
**
** 	Input:		iMin (int) and iMax (int)
**
** 	Output:		Random Number (int) between iMin and iMax
**
**  References: http://www.cplusplus.com/reference/cstdlib/rand/
**
***************************************************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h> //abs, rand
#include <time.h>   //Time, for randomization


int rand_int(int iMin, int iMax);

int main()
{
    int iMin, iMax;

    std::cout << "We are going to generate a random number.\nPlease enter a min and max value "
              << "(int int):";
    std::cin >> iMin >> iMax;

    std::cout << "\n\nBehold...a psuedo random number.\n\n" << rand_int(iMin, iMax) << std::endl;
    //statements

    return 0;
}

int rand_int(int iMin, int iMax)
{
    srand(time(NULL));
    return (rand() % iMax + iMin);
}
