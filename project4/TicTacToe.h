#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
public:
    //member functions
    TicTacToe();    //constructor
    void playGame();     //run game

    //public variables
private:
    //member function
    bool checkVictory(char arr[]);
    bool is_odd(int n);
    bool playerMove(char arr[]);

    int checkForBlock(char arr[]);
    int randomMove(char arr[]);
    int rand_int(int iMin, int iMax);
    int winOrBlock(char arr[],char testChar);

    void computerMove(char arr[]);
    void getValidInput(int &input);
    void getValidMove(int move, char arr[]);
    void makeMove(char arr[], int move, char piece);
    void printBoard(char arr[]);

    //private variables
};

#endif // TICTACTOE_H
