/**************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Modified by:    Benjamin Hobbs
 ** Date Created:   2/1/2014
 ** Last Mod. Date: 2/7/2014
 ** Overview:       This program is a single player hangman.  Chooses n words and has the player
 **                 guess them, letter by letter, word by word until they succeed or fail.
 ** Input:		    none
 ** Output:		    none
 *************************************************************************************************/
#include "PhraseGuess.h"
#include <iostream>	//std::cout, std::cin
#include <string>	//std::string
#include <algorithm>// std::sort
#include <stdlib.h> //abs, rand
#include <time.h>   //Time, for randomization

/**************************************************************************************************
 ** Function:       constructor
 ** Description:    ...
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
PhraseGuess::PhraseGuess()
{
    iMin = 1;
    iMax = 5;
}

/**************************************************************************************************
 ** Function:       ...
 ** Description:    ...
 ** Input:          ... || ...
 ** Output:         ... || ...
 *************************************************************************************************/
void PhraseGuess::playGame()
{
    std::string str_secretWord; //secret word

    do
    {
        bool success = false;
        int round = 0, numWords = 0;

        numWords = rand_int(iMin, iMax);

        std::cout << "\n\n\nWord Guessing Game\n\n\n(Kinda like hangman)\n\n\n"
                  << "To win, successfully guess the letters in " << numWords
                  << " random words.\n\n";
        do
        {
            randomWord(str_secretWord);  //setup guess word

            success = guessTheWord( str_secretWord );   //run the game

            round++;    //increase the round number

            if ( success == true && round < numWords )  //conditional checks for vic conditons
            {
                std::cout << "\n\nCongratulations, you only have to guess " << numWords - round
                          << " more words until you win.\n\n";
                success = true;
            }
            else if ( success == true && round == numWords )
            {
                std::cout << "\n\nCongratulations, you win...you're a real winner.\n\n";
                success = false;
            }
            else
            {
                std::cout << "\n\nYou Fail!\n\nThe word was " << str_secretWord << std::endl
                          << "You missed: " << missedChars << std::endl;
                success = false;
            }   //end conditional
        } while (success != false);
    } while ( playAgain() );    //calls playAgain function

    //return 0;
}

/**************************************************************************************************
 ** Function:       getWord
 ** Description:    Returns a random word from list.
 ** Input:          str str (by ref)    || holds secret word
 ** Output:         str str (by ref)    || holds secret word
 *************************************************************************************************/
void PhraseGuess::randomWord(std::string &str)
{
    std::string arr[10] = {"mosey","whimsical","caprice","beguile","dulcet","insouciance",
                           "luminescence","mellifluous","opulent","cacophony"};
    str = arr[rand_int(0,9)];
}

/**************************************************************************************************
 ** Function:       rand_int
 ** Description:    Given a high and low input, returns psuedo random number between
 ** Input:          int iMin        || low value for random
 **                 int iMax        || high value for random
 ** Output:         int (return)    || returns pseudo random number
 *************************************************************************************************/
int PhraseGuess::rand_int(int iMin, int iMax)
{
    srand(time(NULL));
    return (rand() % iMax + iMin);
}

/**************************************************************************************************
 ** Function:       guessTheWord
 ** Description:    Runs the game
 ** Input:          str strSecretWord   || the secret word
 ** Output:         bool (return)       || returns true if player won the game, else false
 *************************************************************************************************/
bool PhraseGuess::guessTheWord(std::string str)
{
    bool bSuccess = false;
    int len = str.length(), guesses = (len);      //number of guesses
    char guess, arrSecretWord[len], arrGuess[len];          //guess, arr 4 word, arr for correct guesses
    std::string sGuessedLetters;                            //string with all guessed letters

    for (int i = 0; i < len; i++)               //initialize secret word and guess array
    {                                           //
        arrSecretWord[i] = str.at(i); //init. secret word array with correct letters
        arrGuess[i] = '?';                      //init. arrGuess with ? s
    }

    do
    {
        bool bGuess = false;

        printGuess(len, guesses, arrGuess, sGuessedLetters);  //print guess promt

        std::cout << "Please enter a letter: ";
        std::cin >> guess;

        if ( checkGuess(guess, sGuessedLetters) )
        {
            for (int j = 0; j < len; j++)           //Check guess
            {
                if ( guess == arrSecretWord[j] )    //If guess is correct
                {
                    arrGuess[j] = guess;            //assigns letter to correct position in guess arr
                    bGuess = true;
                }
            }

            bGuess ? guesses++ : guesses;   //no penalty for correct guesses

            if ( gameSuccess( len , arrSecretWord , arrGuess ) )    //determine if user 2 wins
            {
                bSuccess = true;
                break;
            }
        }
        else    //catches illegal guesses
        {
            showRemainingChars(sGuessedLetters);
            guesses++;
        }

    } while ( guesses-- > 1);

    return bSuccess;
}

/**************************************************************************************************
 ** Function:       gameSuccess
 ** Description:    Runs at the end of each guess to see if the user has won the game, also sets
 **                 the missed chars string.
 ** Input:          int len                 || length of secret word
 **                 char arrSecretWord[]    || array, secret word as chars
 **                 char arrGuess[]         || array, guessed letters, ? for unguessed chars
 ** Output:         bool (return)           || false if secret word and guess dont match: else true
 *************************************************************************************************/
bool PhraseGuess::gameSuccess(int len, char arrSecretWord[], char arrGuess[])
{
    missedChars = "";
    for ( int i = 0 ; i < len ; i++ )
    {
        if ( arrSecretWord[i] != arrGuess[i] )
        {
            missedChars = missedChars + arrSecretWord[i];
        }
    }

    for ( int i = 0 ; i < len ; i++ )
    {
        if ( arrSecretWord[i] != arrGuess[i] )
        {
            return false;
        }
    }

    return true;
}

/**************************************************************************************************
 ** Function:       checkGuess
 ** Description:    Makes sure that the guess is valid.
 ** Input:          char guess                      || the current guess
 **                 str sGuessedLetters (by ref)    || all guessed letters
 ** Output:         bool (return)                   || false, guess is not valid || otherwise true
 *************************************************************************************************/
bool PhraseGuess::checkGuess(char guess, std::string &sGuessedLetters)
{
    int i = 0;

    if ( islower( int (guess) ) ==0 )  //check if lower
    {
        return false; //exit function
    }

    while ( i < sGuessedLetters.length() )      //loop checks if char already guessed
    {
        if ( sGuessedLetters.at(i) == guess )
        {
            return false; //exit function
        }
        i++;
    }

    sGuessedLetters = sGuessedLetters + guess;      //place guessed lettes
    std::sort(sGuessedLetters.begin(), sGuessedLetters.end());

    return true;
}

/**************************************************************************************************
 ** Function:       showRemainingChars
 ** Description:    Lets the user know if they used an illegal char, also creates string of missed
 **                 chars which is shown if the user loses the game.
 ** Input:          str sGuessedLetters || holds currently guessed letters
 ** Output:         none
 *************************************************************************************************/
void PhraseGuess::showRemainingChars(std::string sGuessedLetters)
{
    std::string allLetters = "abcdefghijklmnopqrstuvwxyz";

    std::cout << "\n\n\nThe character you entered is an illegal character or you have already "
              << "entered it.  The following letters are valid and have not been entered:\n\n";

    for ( int i = 0 ; i < sGuessedLetters.length() ; i++ )
    {
        allLetters.erase(std::remove(allLetters.begin(),allLetters.end(),sGuessedLetters.at(i)),allLetters.end());
    }

    for ( int i = 0 ; i < allLetters.length() ; i++ )
    {
        std::cout << allLetters.at(i) << " ";
    }

    std::cout << "\n\nPlease hit any key to continue back to the game:";
    std::cin.get();
    std::cin.ignore();
}

/**************************************************************************************************
 ** Function:       printGuess
 ** Description:    Prints the guess, in the correctly formatted form
 ** Input:          int len             || length of secret word
 **                 int guessesLeft     || number of guesses remaining
 **                 char arrGuess[]     || array of chars (correctly guessed letters in secret wd)
 **                 str sGuessedLetters || all guessed letters
 ** Output:         ...
 *************************************************************************************************/
void PhraseGuess::printGuess(int len, int guessesLeft, char arrGuess[], std::string sGuessedLetters)
{
    std::string wPad, bPad, gPad, g1Pad;                               //Set up the formatting

    buildPad(wPad,(len - 4 ) / 2,' ');
    buildPad(bPad,(len + 33),'-');

    std::cout << wPad << "Word" << wPad << " - " << "Guessed letters - Guesses Left\n"  //print first line
              << bPad << std::endl;

    for (int i = 0; i < len; i++)           //print second line
    {
        std::cout << arrGuess[i];
    }

    buildPad(gPad,(15 - sGuessedLetters.length()),' ');
    buildPad(g1Pad,5, ' ');

    std::cout << " - " << sGuessedLetters << gPad << " - " << g1Pad << guessesLeft << g1Pad << "|  ";
}

/**************************************************************************************************
 ** Function:       buildPad
 ** Description:    Builds pad of chars to help format each guess
 ** Input:          str pad (by ref)    || holds the finished padding for formatting
 **                 int len             || # of chars to pad str pad
 **                 char filler         || char to use as filler
 ** Output:         str pad (by ref)    || string of padding chars
 *************************************************************************************************/
void PhraseGuess::buildPad(std::string &pad, int len, char filler)
{
    for (int i = 0; i < len ; i++)
    {
        pad = pad + filler;
    }
}

/**************************************************************************************************
 ** Function:       playAgain
 ** Description:    Lets user play again if they want
 ** Input:          none
 ** Output:         bool (return)   || 1; continue game || 0; end game
 *************************************************************************************************/
bool PhraseGuess::playAgain()
{
    char cExit;

    std::cout << "\n\nRun again?\n(y/n): ";
    std::cin >> cExit;
    std::cin.ignore(50,'\n'); //clear buffer

    if (cExit != 'n')
    {
        return 1;
    }

    return 0;
}
