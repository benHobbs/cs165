/**************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Modified by:    Benjamin Hobbs
 ** Date Created:   1/14/2014
 ** Last Mod. Date: 2/7/2014
 ** Overview:       Number guessing game.  System picks a random number and gives the user x
 **                 guesses to determine said number.
 ** Input:		    none
 ** Output:		    none
 *************************************************************************************************/
#include "NumberGuess.h"
#include <iostream>	    //std::cout, std::cin
#include <stdlib.h>     //abs, rand
#include <time.h>       //Time, for randomization

/**************************************************************************************************
 ** Function:       constructor
 ** Description:    ...
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
NumberGuess::NumberGuess()
{
    //left blank
}

/**************************************************************************************************
 ** Function:       setParams
 ** Description:    ...
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void NumberGuess::setParams()
{
    guessMin = 0;
    guessMax = rand_int(50,100);    //sets the high number between 50 and 100
    guessTarget = rand_int(guessMin,guessMax);  //sets secret num between low and high
    guessNumber = 5;
    bFail = true;
}

/**************************************************************************************************
 ** Function:       rand_int
 ** Description:    ...
 ** Input:          high and low for random number
 ** Output:         int random number
 *************************************************************************************************/
int NumberGuess::rand_int(int iMin, int iMax){
    srand(time(NULL));
    return (rand() % iMax + iMin);
}

/**************************************************************************************************
 ** Function:       playGame
 ** Description:    Runs the number guess game
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void NumberGuess::playGame()
{
    introText();

    do  //loop so that user can replay if desired
    {
        setParams();
        roundIntro();
        for ( int j = 1 ; j <= guessNumber ; j++ ) {  //for loop runs for each guess
            guessIntro(j);
            if ( guess == guessTarget ){
                std::cout << "\n\n\nCongratz...You Win\n\n\n";
                bFail = false;
                break;
            }
            else if ( guess > guessTarget){
                std::cout << "This guess was too high...";
                if ( guess < guessMax ){     //reset max if guess was lower than current max
                    guessMax = guess;
                }
            }
            else if ( guess < guessTarget){
                std::cout << "This guess was too low...";
                if ( guess > guessMin ){
                    guessMin = guess;
                }
            }

            if ( ( abs ( guessTarget - guess) ) < guessClosest ){
                guessClosest = ( abs ( guessTarget - guess) );
            }
        }
        if ( bFail == true ){    //only runs when user used up all guesses
            std::cout << "Sorry, you ran out of guesses.\nThe number was " << guessTarget
                      << ".\nYour closest guess was off by " << guessClosest << ".";
        }

        std::cout << "\n\nWould you like to play again?\n(y/n): ";
        std::cin >> cExit;
    } while ( cExit != 'n' );

    std::cout <<"Done";
}

/**************************************************************************************************
 ** Function:       introText
 ** Description:    Prints intro text
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void NumberGuess::introText(){
    std::cout << "**************************************************\n";
    std::cout << "*               Number Guess Game                *\n";
    std::cout << "*                                                *\n";
    std::cout << "*  Player will be given a low number and a high  *\n";
    std::cout << "*  number.  The computer will set a secret num-  *\n";
    std::cout << "*  ber between the low and high number and give  *\n";
    std::cout << "*  the player a random number of guesses to gu-  *\n";
    std::cout << "*  ess the secret number.  Good Luck!            *\n";
    std::cout << "*                                                *\n";
    std::cout << "**************************************************\n";
}

/**************************************************************************************************
 ** Function:       roundIntro
 ** Description:    Prints intro text for round
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void NumberGuess::roundIntro(){
    std::cout << "Please guess the secret number.\nThe number is between " << guessMin
              << " and " << guessMax << ".\nYou have been given " << guessNumber
              << " guesses.\nGood Luck!\n";
}

/**************************************************************************************************
 ** Function:       guessIntro
 ** Description:    Prints intro text for each guess
 ** Input:          guess number as int
 ** Output:         none
 *************************************************************************************************/
void NumberGuess::guessIntro(int guessJ){
    std::cout << "\n\n\nGuess (" << guessJ << " of " << guessNumber << ")\n"
              << "Guess (between " << guessMin << " and " << guessMax << ": ";
    std::cin >> guess;
    std::cout << "\n\nYou guessed " << guess << ".\n";
}
