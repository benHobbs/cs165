#ifndef PHRASEGUESS_H
#define PHRASEGUESS_H

#include <string>

class PhraseGuess
{
public:
    PhraseGuess();
    void playGame();
private:
    //member functions
    bool checkGuess(char guess, std::string &sGuessedLetters);          //catches multiple guesses
    bool guessTheWord(std::string str);                                 //The game
    bool gameSuccess(int len, char arrSecretWord[], char arrGuess[]);   //checks if player won
    bool playAgain();                                                   //checks for round 2

    int rand_int(int iMin, int iMax);                                   //generates random number

    void buildPad(std::string &pad, int len, char filler);              //creates padding 4 formatting
    void printGuess(int len, int guessesLeft, char arrGuess[], std::string sGuessedLetters);
    void randomWord(std::string &str);                                   //grabs a random word
    void showRemainingChars(std::string sGuessedLetters);

    int iMin, iMax;     //low, high for # of words in phrase guess
    std::string missedChars;
};

#endif // PHRASEGUESS_H
