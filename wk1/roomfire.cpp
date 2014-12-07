/*******************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/14/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Programming Project 1.5
** 	Filename: roomfire.cpp
**
** 	Overview: 	This program will determine the legality of a meeting, in terms
**				of the firecode and number of persons attending.
**
** 	Input:		2 User inputs: # of persons attending meeting (int iAttendees)
**							   Fire code max capacity (int iCap)
**
** 	Output:		|	If the meeting meets fire code
**				|	Conditional (if above is true), how many more people
**					could attend.
**
********************************************************************************/

//Macros
#include <iostream>

int main() {
	int iAttendees;	//var for people attending
	int iCap;		//var for room fire code capacity
	
	std::cout << "How many people are attending this meeting? ";
	std::cin >> iAttendees;		//Get number of people attending meeting
	
	std::cout << "What is the capacity (fire code) of the meeting room? ";
	std::cin >> iCap;	//Get room capacity
	
	if (iAttendees <= iCap) {
		std::cout << "This meeting is NOT in violation of the fire code.\n"
				  << "There is/are " << iCap - iAttendees
				  << " slot(s) available." << std::endl;
	}
	else {
		std::cout << "This meeting IS in violation of the fire code.\n"
				  << "Please get a larger room or exclude " << iAttendees - iCap
				  << " persons." << std::endl;
	}
	
	return 0;
}