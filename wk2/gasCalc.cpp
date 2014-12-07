/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/18/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Excercise 4 Problem 3
** 	Filename: gasCalc.cpp
**
** 	Overview: 	This program calculates miles per gallon when provided liters of petrol and milage
**              travelled.
**
** 	Input:      Petrol (in Liters) float
**              Miles travelled float
**
** 	Output:		Miles per gallon (float)
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin

//type name();	//func. proto.

const float literInGallons = 0.264179;  //liters in a gallon

float litersToGallons( float liters );  //proto liters to gallons function
float mpgCalc( float gallons, float miles );    //proto mpg calculation function

int main()
{
    char cExit;
    float liters = 0, mpg = 0, miles = 0;

    do
    {
        std::cout << "MPG Calculator:\n\nPlease enter liters of petrol consumed: ";
        std::cin >> liters;
        std::cout << "\nPlease enter miles travelled: ";
        std::cin >> miles;

        mpg = mpgCalc( miles , litersToGallons( liters ) ); //pass liters to gallonCalc function
                                                            //then passes gallons to mpg function
                                                            //returns mpg

        std::cout << "\n\nPetrol consumption in Liters: " << liters
                  << "\n\nDistance travelled in Miles: " << miles << "\n\nTotal MPG: " << mpg
                  << std::endl;

        std::cout << "\n\nRun again?\n(y/n): ";     //exit sequence
        std::cin >> cExit;                          //
    } while ( cExit != 'n' );                       //

    std::cout << std::endl;

    return 0;
}

float litersToGallons( float liters )   //Converts liters to gallons
{
    return (liters * literInGallons);
}

float mpgCalc( float miles, float gallons ) //Calculates miles per gallon
{
    return ( miles / gallons );
}
