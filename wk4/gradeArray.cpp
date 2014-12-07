/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/28/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Ex. 6 Problem 3 (p233)
** 	Filename: gradeArray.cpp
**
** 	Overview:   This program will take n inputs of int 1 - 5.  At the end (when e is submitted),
**              the program will return a table of the grades.
**
** 	Input:		user int for each grade
**
** 	Output:		List of grades
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin

void getGrades(int arrGrades[]);
void getValidInput(int &input); //gets valid entry

int main()
{
    int arrGrades[6] = {0,0,0,0,0,0};

    getGrades(arrGrades);

    for ( int i = 0 ; i <= 5 ; i++ )
    {
        std::cout << arrGrades[i] << " grade(s) of " << i << std::endl;
    }

    return 0;
}

void getGrades(int arrGrades[])
{
    int input = -1;

    do  //do...while loop exits on '9'
    {
        input = -1; //set input to invalid entry
        std::cout << "Please enter a grade (0-5) or '9' to exit: ";

        getValidInput(input);

        if (input == 9)
        {
            break;
        }
        else if ( input < 0 || (input > 5 && input < 9) || input > 9 )    //any invalid case
        {
            std::cout << "This number is not a valid grade or the exit number.  ";
        }
        else
        {
            arrGrades[input]++;   //increase correct grade element
        }
    } while ( input != 9);
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
            }
            std::cout << "Please enter a valid input: ";
        }
}
