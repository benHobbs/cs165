#ifndef NUMBERGUESS_H
#define NUMBERGUESS_H

class NumberGuess
{
public:
    NumberGuess();
    void playGame();

private:
    //member functions
    int rand_int(int iMin, int iMax);

    void introText();
    void setParams();
    void roundIntro();
    void guessIntro(int guessJ);

    //vars
    bool bExit, bFail;
    char cExit;
    int guessMin, guessMax, guessTarget, guessNumber, guess, guessClosest;
};

#endif // NUMBERGUESS_H
