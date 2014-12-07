/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/28/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Ex. 6 Problem 3 (p233)
** 	Filename: gradeArray.cpp
**
** 	Overview:   This program will ask the user for the highest possible grade in the class.  Create
**              an array that holds grades from 0 to the highest possible grade.  Prompt the user
**
**              the program will return a table of the grades.
**
** 	Input:		user int for each grade
**
** 	Output:		List of grades
**
***************************************************************************************************/
#include <iostream>	    //std::cout, std::cin
#include <algorithm>    //sort array
#include <cmath>        // std::abs

void getGrades(int high, int arrGrades[]);
void getHigh(int &high);
void getValidInput(int &input); //gets valid entry


int main()
{
    bool bPass = false;
    int low = 0, high = 0;    //length of dynamic array

    std::cout << "Grade Program\n\n";

    while ( bPass != true )
    {
        std::cout << "Please enter the high grade for the class (int): ";
        getValidInput(high);
        if ( high < 0 )
        {
            std::cout << "This is below the low grade.  ";
        }
        else
        {
            bPass = true;
        }
    }


    int *arrGrades = new int[abs(high - low)+1];   //declare dynamic array

    for ( int i = 0 ; i <= high ; i++ )
    {
        arrGrades[i] = 0;
    }

    getGrades(high, arrGrades);

    for ( int i = 0 ; i <= abs(high - low) ; i++ )
    {
        std::cout << arrGrades[i] << " grade(s) of " << i << std::endl;
    }

    delete [] arrGrades;     //clear memory

    return 0;
}

void getGrades(int high, int arrGrades[])
{
    int input = -1;

    do  //do...while loop exits on '9'
    {
        input = -1; //set input to invalid entry

        std::cout << "Please enter grade (0 to " << high << ") (-1 exits) (int): ";

        getValidInput(input); //get valid input (int)

        if (input == -1)
        {
            break;
        }
        else if ( input < -1 || input > high )    //any invalid case
        {
            std::cout << "This number is not a valid grade or the exit number.  ";
        }
        else
        {
            arrGrades[input]++;   //increase correct grade element
        }
    } while ( input != -1);
}

void getValidInput(int &input)      //takes a variable and catches non-valid entries
                                    //cleans up on error and requests new input
{
        while(!(std::cin >> input))                         //catches non int entries
        {
            std::cin.clear();               //clear stream
            while(std::cin.get()!= '\n')    //ignores errors before \n escape char
            {
                continue;
            }   //end while loop
            std::cout << "Please enter a valid input: ";
        }   //end while loop
}
