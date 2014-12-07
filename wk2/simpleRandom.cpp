/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/17/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Excercise Set 3, Problem 3
** 	Filename: simpleRandom.cpp
**
** 	Overview: 	Using rand and srand to create 10 random numbers.  This program will reset the
**              random number generator on each pass to gain max. randomness.
**
** 	Input:		n/a
**
** 	Output:		10 random numbers between 1-1000;
**
**  References: http://www.cplusplus.com/reference/cstdlib/rand/
**
**
***************************************************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h> //abs, rand
#include <time.h>   //Time, for randomization

int main()
{

for ( int i = 0 ; i < 10 ; i++ )
{
    srand(time(NULL));      //init rand generator on each loop, thus time will be slightly different
    std::cout << (rand() % 1000 + 1) << std::endl;     //Range 1 to 1000
}

    return 0;
}
