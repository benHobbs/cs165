/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/18/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Excercise 4 Problem 1
** 	Filename: randNumber.cpp
**
** 	Overview: 	This program uses a function to return a random number (by reference) between two
**              user specified values.
**
** 	Input:		iMin (int) and iMax (int)
**
** 	Output:		Random Number (int) between iMin and iMax
**
**  References: http://www.cplusplus.com/reference/cstdlib/rand/
**
***************************************************************************************************/
#include <iostream>
#include <stdlib.h> //abs, rand
#include <time.h>   //Time, for randomization

//void rand_int(int min, int max, int &val);

void rand_int(int iMin, int iMax, int &val);

int main()
{
    int iMin, iMax, val;

    std::cout << "We are going to generate a random number.\nPlease enter a min and max value "
              << "(int int):";
    std::cin >> iMin >> iMax;

    rand_int(iMin, iMax, val);

    std::cout << "\n\nBehold...a psuedo random number.\n\n" << val << std::endl;

    return 0;
}


void rand_int(int iMin, int iMax, int &val)
{
    srand(time(NULL));
    val = (rand() % iMax + iMin);
}
