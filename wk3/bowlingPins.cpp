/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/22/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Excercise 5, problem 5
** 	Filename: bowlingPins.cpp
**
** 	Overview: 	This program uses a recursive function to determine the number of bowling pins
**              required to make a pyramid of n rows.
**
**                  *     This example, where rows (n) is three, should return 6 bowling pins.
**                 * *
**                * * *
**
** 	Input:		User input n (int)
**
** 	Output:		bowlingPins (int)
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin

int rows(int n);

int main()
{
    int n, pins;

    std::cout << "Please enter the number of rows for your bowling pin pyramid: ";
    std::cin >> n;

    pins = rows(n);

    std::cout << "Pins required for a " << n << " row pyramid: " << pins << std::endl;

    return 0;
}

int rows(int n)
{
    if ( n <= 1 )   //returns 1 if only 1 row is input
    {
        n = 1;
    }
    else    //runs recursive with the row number dropped by one each run
    {
        return n + rows(n - 1);
    }
}

