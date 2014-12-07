/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/22/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Excercise 5, problem 4
** 	Filename: fibonacciNum.cpp
**
** 	Overview: 	A program that takes int n and uses a function to return the nth number of the
**              Fibonacci sequence.  Won't go over 47 because of int limitations.
**
** 	Input:		user input || n (int)
**
** 	Output:		nth number of the fibonacci sequence
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin
#include <string>	//std::string
#include <stdlib.h>	//abs, rand, srand
#include <time.h>	//Time (used to init. randomization)
#include <utility>      //std::swap

int n;  //declared outside of main to keep in scope
void fibNum(int n, int i, int arr[]);

int main()
{
    std::cout << "Fibonacci Number\nPlease enter which number you would like to calculate (n): ";
    std::cin >> n;

    int arr[n];
    arr[1] = 0, arr[2] = 1; //seed fibonacci sequence
    int i = 3;  //set start parameter so that the functions actions

    fibNum(n, i, arr);  //call fibonacci number function

    std::cout << arr[n] << std::endl;

    return 0;
}

void fibNum(int n, int i, int arr[])
{
    if ( i <= n )
    {
        arr[ i ] = arr[ i - 1 ] + arr[ i - 2 ]; //calculate next number in fibonacci sequence
        fibNum(n,i+1,arr);    //recurz
    }
}
