/*******************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/14/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Week 2 Project
** 	Filename: week2_project.cpp
**
** 	Overview: 	A 2 player number guessing program.
**
** 	Input:		Player 1: A number to be guessed (int)
**				Player 1: Number of chances to guess number (int)
**				Player 2: Guesses for the number
**				Either Player: Option to play again
**
** 	Output:		Range for each guess
**				Success/Failure
**				Start Over
**
********************************************************************************/

/**************************************************************************************************/
#include <iostream>

int main() {
	int iMin, iMax, iTargetNum, iNum, iGuess, i;
	char cExit;
	bool bExit;

	do
	{
		std::cout << "Player 1:\nPlease choose a range (int int): ";
		std::cin >> iMin >> iMax;	//get min and max range
		
		do	//This loop is for setting the guess number
		{				
			std::cout << "Please enter a number between " << iMin << " and " << iMax << ": ";
			std::cin >> iTargetNum;
			if (( iMin < iTargetNum ) && (iTargetNum < iMax)) {
				bExit = true;
			} else {
				bExit = false;
			}
		} while ( bExit == false );	//Exits when user has picked appropriate number

		std::cout << "How many guesses will your opponent get? ";
		std::cin >> iNum;
		//check and force rentry if outside
		std::cout << "Let the Game Begin\n\nPlayer 2:\n";
		std::cout << "Please choose a number between " << iMin << " and " << iMax << ":";
		
		bExit = false;

		do
		{
			std::cin >> iGuess;
			if ( iGuess == iNum ) {
				std::cout << "Congrats...you win.\n";
				bExit = true;
			} else if ( iGuess > iNum ) {	//too high
				std::cout << "Too high...\n";
			} else {
				std::cout << "fail.\n";
			};
			std::cout << bExit << std::endl;
		} while ( bExit == false );
/*
		for ( i = 0 ; i <= iNum ; i++ ) {
			std::cin >> iGuess;
			if ( iGuess == iNum ) {		//Guess was correct
				std::cout << "Congrats...you win.\n";
				i = iNum + 1;	//forces exit of loop
			} else if ( iGuess > iNum ) {	//Guess is high
				std::cout << "Too high.\n" << iGuess << iMax;
				iMax = iGuess;
			} else if ( iGuess < iNum ) {	//Guess is low
				std::cout << "Too low.\n";
				iMin = iGuess;
			} else {	//something is very wrong

			}                                                                         
			std::cout << "Player 2:\nYou have " << iNum - i << " guesses left.\n"
				  << "Please choose a number between " << iMin << " and "
				  << iMax << ":";	
		}	
*/
		std::cout << "Would you like to play again?\n(y/n): ";
		std::cin >> cExit;
	} while (cExit != 'n');

	return 0;
}
