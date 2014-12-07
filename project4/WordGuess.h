#ifndef WORDGUESS_H
#define WORDGUESS_H
#include <string>

class WordGuess
{
public:
    WordGuess();
    void playGame();
private:
    //member functions

    bool checkGuess(char guess, std::string &sGuessedLetters);
    bool gameSuccess(int len, char arrSecretWord[], char arrGuess[]);
    bool guessTheWord(std::string str_secretWord);
    bool playAgain();

    int rand_int(int iMin, int iMax);

    void buildPad(std::string &pad, int len, char filler);
    void getWord(std::string &str);
    void printGuess(int len, int guessesLeft, char arrGuess[], std::string sGuessedLetters);
    void showRemainingChars(std::string sGuessedLetters);

    //vars
    std::string missedChars;

};

#endif // WORDGUESS_H
