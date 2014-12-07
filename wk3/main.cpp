/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/21/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Week 2 Project
** 	Filename: week2Pro.cpp
**
** 	Overview:   This program is essentially a poor mans hangman.  Takes a secret word, lets the
**              second user guess one letter at a time.
**
** 	Input:		User input || secretword str
**                            guesses char
**
** 	Output:		Success or Failure (on failure should show word)
**
**  Learned:    Can't pass multidimensional arrays...
**
**  References:
**      http://www.cplusplus.com/forum/general/11059/ || \b escape character
**      http://www.cplusplus.com/reference/algorithm/sort/ || sort function
**      http://www.cplusplus.com/forum/articles/14631/ || ternary operator
**      http://www.cplusplus.com/reference/cctype/islower/  || is lower
**      http://stackoverflow.com/questions/5891610/how-to-remove-characters-from-a-string
**      http://www.cplusplus.com/reference/istream/istream/ignore/
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin
#include <string>	//std::string
#include <algorithm>// std::sort

bool gameSuccess(int len, char arrSecretWord[], char arrGuess[]);   //checks if player won
bool guessTheWord(std::string str_secretWord);                      //the game component
bool isWord(std::string &str);                                      //check if valid word
bool playAgain();                                                   //checks for round 2
void buildPad(std::string &pad, int len, char filler);              //creates padding 4 formatting
bool checkGuess(char guess, std::string &sGuessedLetters);          //catches multiple guesses
void getWord(std::string &str);                                     //gets secret word
void printGuess(int len, int guessesLeft, char arrGuess[], std::string sGuessedLetters);
void showRemainingChars(std::string sGuessedLetters);

std::string missedChars;

int main()
{
    std::string str_secretWord; //secret word

    do
    {
        std::cout << "\n\n\nWord Guessing Game\n\n\n(Kinda like hangman)\n\n\nPlayer 1, please enter your "
                  << "witty and hard to guess word";

        getWord(str_secretWord);

        if ( guessTheWord(str_secretWord) )
        {
            std::cout << "\n\nYou Win!\n\n";
        }
        else
        {
            std::cout << "\n\nYou Fail!\n\nThe word was " << str_secretWord << std::endl
                      << "You missed: " << missedChars << std::endl;
        }

    } while ( playAgain() );    //calls playAgain function

    return 0;
}

bool guessTheWord(std::string strSecretWord)
{
    bool bSuccess = false;
    int len = strSecretWord.length(), guesses = (len);      //number of guesses
    char guess, arrSecretWord[len], arrGuess[len];          //guess, arr 4 word, arr for correct guesses
    std::string sGuessedLetters;                            //string with all guessed letters

    for (int i = 0; i < len; i++)               //initialize secret word and guess array
    {                                           //
        arrSecretWord[i] = strSecretWord.at(i); //init. secret word array with correct letters
        arrGuess[i] = '?';                      //init. arrGuess with ? s
    }

    do
    {
        bool bGuess = false;

        for ( int i = 0 ; i < 50 ; i++ )    //gives some breathing room
        {
            std::cout << "\n";
        }

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
