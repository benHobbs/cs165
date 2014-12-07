/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 2/1/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Week 3 Project
** 	Filename: week3Pro.cpp
**
** 	Overview:   This program is a single player hangman.  Chooses n words and has the player guess
**              them, letter by letter, word by word until they succeed or fail.
**
** 	Input:		guesses char
**
** 	Output:		Success or Failure (on failure should show word)
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin
#include <string>	//std::string
#include <algorithm>// std::sort
#include <stdlib.h> //abs, rand
#include <time.h>   //Time, for randomization

bool guessTheWord(std::string str);                                 //The game
int rand_int(int iMin, int iMax);                                   //generates random number
bool gameSuccess(int len, char arrSecretWord[], char arrGuess[]);   //checks if player won
bool playAgain();                                                   //checks for round 2
void buildPad(std::string &pad, int len, char filler);              //creates padding 4 formatting
bool checkGuess(char guess, std::string &sGuessedLetters);          //catches multiple guesses
void printGuess(int len, int guessesLeft, char arrGuess[], std::string sGuessedLetters);
void showRemainingChars(std::string sGuessedLetters);
void randomWord(std::string &str);                                   //grabs a random word

std::string missedChars;
const int iMin = 1, iMax = 5;

int main()
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

    return 0;
}

void randomWord(std::string &str)
{
    std::string arr[10] = {"mosey","whimsical","caprice","beguile","dulcet","insouciance",
                           "luminescence","mellifluous","opulent","cacophony"};
    str = arr[rand_int(0,9)];
}

int rand_int(int iMin, int iMax)
{
    srand(time(NULL));
    return (rand() % iMax + iMin);
}

bool guessTheWord(std::string str)
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

bool gameSuccess(int len, char arrSecretWord[], char arrGuess[])    //runs at the end of each
{                                                                   //guess to see if the user
    missedChars = "";                                               //has won the game, also
    for ( int i = 0 ; i < len ; i++ )                               //sets the missed chars
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

bool checkGuess(char guess, std::string &sGuessedLetters)
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

void showRemainingChars(std::string sGuessedLetters)
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

void printGuess(int len, int guessesLeft, char arrGuess[], std::string sGuessedLetters)
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

void buildPad(std::string &pad, int len, char filler)
{
    for (int i = 0; i < len ; i++)
    {
        pad = pad + filler;
    }
}

/*
void getWord(std::string &str)
{
    do
    {
        std::cout << "\n(only letters please; between 4 and 14 letters):  ";
        getline(std::cin, str);

    } while ( isWord (str) != 1 );

    for ( int i = 0 ; i <= 50 ; i++ )
    {
        std::cout << "\n";
    }
}

bool isWord(std::string &str)
{
    for ( int i = 0 ; i < str.length() ; i++ )
    {
        if ( isalpha( int ( str.at( i ) ) ) == 0 )
        {
            return false;
        }
    }

    for ( int i = 0 ; i < str.length() ; i++ )
    {
        if ( islower( int ( str.at( i ) ) ) == 0 )
        {
            return false;
        }
    }

    if ( str.length() < 4 || str.length() > 14 ) //word must be at least 4 chars long
    {
        return false;
    }

    return true;
}
*/

bool playAgain()
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
