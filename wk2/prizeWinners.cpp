/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/19/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Excercise 4, Problem 5
** 	Filename: prizeWinners.vpp
**
** 	Overview: 	This program will declare the winners out of a pool of 25 finalists.  There should
**				not be any repeat winners.
**
** 	Input:		None
**
** 	Output:		4 winners (between 1 and 25)
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin
#include <stdlib.h>	//abs, rand, srand
#include <time.h>	//Time (used to init. randomization)

//type name();	//func. proto.
int rand_int(int iMin, int iMax);

int main()
{
    const int finalists = 25;
    int nums[4], iMin = 1, iMax = finalists;    //will store the winning numbers


    std::cout << "Your winners:" << std::endl;

    for ( int i = 0 ; i < 4 ; i++ )    //runs a loop to choose winners
    {
        for ( int j = 0 ; j < 4 ; j++ ) //checks for already existing winner
        {

            int test = rand_int(iMin, iMax);

            if ( test == nums[j] )
            {
                j--;
            }
            else
            {
                nums[i] = test;
            }
        }
        std::cout << nums[i] << std::endl;
    }

    return 0;
}


int rand_int(int iMin, int iMax)
{
    srand(time(NULL));
    return (rand() % iMax + iMin);
}
