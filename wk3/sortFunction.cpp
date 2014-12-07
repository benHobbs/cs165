/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/21/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Excercise Set 5, Problem 3 ( p.183 )
** 	Filename: sortFunction.cpp
**
** 	Overview: 	This program takes three ints and passes them to a function called sort.  The sort
**              function puts them into ascending order by value and returns them by reference.
**
** 	Input:		No user input.
**
** 	Output:		3 ints, in acs order by value.
**
**  References: http://www.cplusplus.com/reference/utility/swap/  || for swap
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin
#include <utility>      // std::swap

void sort(int& a, int& b, int& c);

int main()
{
    int a = 30, b = 10, c = 20;

    sort( a,b,c );
    std::cout << a << std::endl << b << std::endl << c << std::endl;

    return 0;
}

void sort(int& a, int& b, int& c)   //this function sorts the three ints into asc order by value
{
    if ( b > c )
    {
        std::swap( b , c );
    }
    else if ( a > c )
    {
        std::swap( a , c );
    }

    if ( a > b )
    {
        std::swap( a , b );
    }

}
