/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/18/2014
** 	Last Modification Date: 1/19/2014
** 	Lab/Project#: Excercise 4 Problem 4
** 	Filename: clothingSize.cpp
**
** 	Overview: 	Program to calculate clothing sizes.
**
** 	Input:		age (int)
**              height (inches) (float)
**              weight (lbs.) (float)
**
** 	Output:		Hat Size
**              Jacket Size
**              Waist Size
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin
#include <string>	//std::string
#include <stdlib.h>	//abs, rand, srand
#include <time.h>	//Time (used to init. randomization)

//type name();	//func. proto.

float hatSize( float height, float weight );  //proto hat size function
float jacketSize( float height, float weight, int age );    //proto jacket size function
float waistSize( float weight, int age );   //proto waist size function

int main()
{
    char cExit;
    float height, weight;
    int age;

    do
    {
        std::cout << "\nClothing Size Calculator:\n\nPlease enter your age: ";
        std::cin >> age;
        std::cout << "\nPlease enter your height (in inches): ";
        std::cin >> height;
        std::cout << "\nPlease enter your weight (in lbs.): ";
        std::cin >> weight;

        //std::cout.setf(ios::fixed);
        //std::cout.setf(ios::showpoint);
        //std::cout.precision(1);

        std::cout << "\n\nYour sizes are as follows:"
                  << "\nHat Size: " << hatSize( height , weight )
                  << "\nJacket Size: " << jacketSize( height , weight , age )
                  << "\nWaist Size: " << waistSize( weight , age )
                  << std::endl;


        std::cout << "\n\nRun again?\n(y/n): ";     //exit sequence
        std::cin >> cExit;                          //
    } while ( cExit != 'n' );                       //

    std::cout << std::endl;

    return 0;
}

float hatSize( float height, float weight )
{
    return (( weight / height ) * 2.9);
}

float jacketSize( float height, float weight, int age )
{
    return ( ( ( height * weight ) / 288 ) + ( .125 * ( int( (age - 30) / 10) ) ) ); //dirty dirty
                                                                                    //math
}

float waistSize( float weight, int age )
{
    return ( ( weight / 5.7 ) + ( .1 * ( int ( ( age - 28 ) / 2 ) ) ) );    //dirty dirty math
}

