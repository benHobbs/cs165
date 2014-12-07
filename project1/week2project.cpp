/***************************************************************************************************
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
**  References: http://www.cplusplus.com/reference/cstdlib/ (stdlib.h abs function)
**
***************************************************************************************************/
#include <iostream>
#include <stdlib.h>

int main()
{
    bool bExit;
    bool bFail; //used if P2 runs out of guesses
    char cExit;
    int guessMin, guessMax, guessTarget, guessNumber, guess, guessClosest;

    do  //loop so that user can replay if desired
    {
        std::cout << "\n\n\n\nWelcome to the GAME\n\n\n\nFirst we need Player 1 to set up the "
                  << "games parameters.\nPlease enter the range for the guessing game (int int): ";
		std::cin >> guessMin >> guessMax;	//get min and max range
        std::cout << "\nNext please enter the number to be guessed.\n";

		do	//This loop is for setting the guess number
		{
			std::cout << "(between " << guessMin << " and " << guessMax << "): ";
			std::cin >> guessTarget;
			if ( ( guessMin < guessTarget ) && (guessTarget < guessMax) )
            {
                guessClosest = guessMax;    //so any future guess will be lower
				bExit = true;
			}
			else
			{
				bExit = false;
			}
		} while ( bExit == false );	//Exits when user has picked appropriate number

        std::cout << "\nAnd lastly, how many guesses will you allow your opponent? ";
        std::cin >> guessNumber;

        for ( int i = 0 ; i < 50 ; i++ )    //moves down to hide player 1 info
        {
            std::cout << std::endl;
        }

        std::cout << "Let the GAME Begin!\n\n\nPlayer 2 please guess the secret number.\n"
                  << "The number is between " << guessMin << " and " << guessMax << ".\n"
                  << "You have been given " << guessNumber << " guesses.\nGood Luck!\n";
        bFail = true;

        for ( int j = 1 ; j <= guessNumber ; j++ ) {  //for loop runs for each guess

            std::cout << "\n\n\nGuess (" << j << " of " << guessNumber << ")\n"
                      << "P2_Guess (between " << guessMin << " and " << guessMax << ": ";

            std::cin >> guess;

            std::cout << "\n\nYou guessed " << guess << ".\n";

            if ( guess == guessTarget )
            {
                std::cout << "\n\n\nCongratz...You Win\n\n\n(Lord it over Player 1)\n";
                bFail = false;
                break;
            }
            else if ( guess > guessTarget)
            {
                std::cout << "This guess was too high...";
                if ( guess < guessMax )     //reset max if guess was lower than current max
                {
                    guessMax = guess;
                }
            }
            else if ( guess < guessTarget)
            {
                std::cout << "This guess was too low...";
                if ( guess > guessMin )
                {
                    guessMin = guess;
                }
            }

            if ( ( abs ( guessTarget - guess) ) < guessClosest )
            {
                guessClosest = ( abs ( guessTarget - guess) );
            }
        }
        if ( bFail == true )    //only runs when user used up all guesses
        {
            std::cout << "Sorry, you ran out of guesses.\nThe number was " << guessTarget
                      << ".\nYour closest guess was off by " << guessClosest << ".";
        }

        std::cout << "\n\nWould you like to play again?\n(y/n): ";
        std::cin >> cExit;
    } while ( cExit != 'n' );


    return 0;
}
