#include "TicTacToe.h"
#include <iostream>
#include <stdlib.h> //abs, rand, atoi
#include <time.h>   //Time, for randomization

/**************************************************************************************************
 ** Function:       TicTacToe
 ** Description:    Constructor
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
TicTacToe::TicTacToe(){
    //left blank
}

/**************************************************************************************************
 ** Function:       playGame
 ** Description:    Runs the tic tac toe game
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void TicTacToe::playGame(){
    char cExit;
    do  //do_while used to run game again
    {
        char boardArray[9] = {'1','2','3','4','5','6','7','8','9'};

        std::cout << "\nTic Tac Toe\nLegit Version\n\n";                //print intro

        printBoard(boardArray);                                         //print board

        for ( int i = 0 ; i < 9 ; i++ ){    //game loop (runs for 9 moves or until 0 is entered)
            int activePlayer;

            if (is_odd(i) != true ){    //set info for player 1
                activePlayer = 1;
                if (playerMove(boardArray) != 1 ){//invalid move, do over
                    i--;    //invalid move, do over
                };
            }   //end if
            else {   //set info for computer
                activePlayer = 2;
                computerMove(boardArray);
            }   //end conditional

            if ( checkVictory(boardArray) == true ){   //check for victory, if true victory
                if (activePlayer == 1 ){    //player
                    std::cout << "\n\n\nYou are victorious...Congrats.\n\n";
                }
                else {
                    std::cout << "\n\n\nThe computer is victorious...Bow before me.\n\n";
                }
                break;
            }   //end if/conditional
        }   //end for loop, game is over

        std::cout << "\n\nPlay again?\n(y/n): ";    //exit sequence
        std::cin >> cExit;
    } while ( cExit != 'n' );   //end do_while loop, used to run game again
}

/**************************************************************************************************
 ** Function:       printBoard
 ** Description:    Print out the board
 ** Input:          char arr[]  || 9 element array with pieces marked
 ** Output:         none
 *************************************************************************************************/
void TicTacToe::printBoard(char arr[]){
    std::cout << std::endl;
    for ( int j = 0 ; j < 3 ; j++ ) {
        for ( int i = 0 ; i < 3 ; i++ ) {
            std::cout << arr[(j*3)+i];
        }   //end for loop (i)
        std::cout << std::endl;
    }   //end for loop (j)
}

/**************************************************************************************************
 ** Function:       is_odd
 ** Description:    Returns if input value is odd
 ** Input:          int n           || number to be evaluated
 ** Output:         bool (return)   || true if int n is an odd number, else false
 *************************************************************************************************/
bool TicTacToe::is_odd(int n){
    return n % 2 != 0;
}

/**************************************************************************************************
 ** Function:       playerMove
 ** Description:    Deals with users move (makes sure it is valid, places
 ** Input:          char arr[]      || 9 element array with pieces marked
 ** Output:         bool (return)   || true if move was valid, else false
 *************************************************************************************************/
bool TicTacToe::playerMove(char arr[]){
    int move;

    std::cout << "\nPlease choose a move: ";
    getValidInput(move);    //get int as input

    if ( (!( move < 1 || move > 9 )) && arr[move-1] != 'X' && arr[move-1] != 'O'){
        makeMove(arr, move, 'X');
        return true;
    }   //end if
    else{    //invalid entry
        std::cout << "You have entered an invalid square...Let's try that again.\n\n";
        return false;
    }   //end else/conditional
}

/**************************************************************************************************
 ** Function:       computerMove
 ** Description:    Makes the computers move: first checks for needed blocking move, then chooses
 **                 available move at random.
 ** Input:          char arr[]  || 9 element array with pieces marked
 ** Output:         none
 *************************************************************************************************/
void TicTacToe::computerMove(char arr[]){
    int move = move = winOrBlock(arr,'O');  //pass to win
    if (move == -1 ){
        move = winOrBlock(arr,'X');    //pass to block
    }
    if ( move == -1 ){  //pass to random
        move = randomMove(arr);
    }
    std::cout << "\nComputer move: " << move << std::endl;  //show comp move
    makeMove(arr,move,'O'); //place the piece
}

/**************************************************************************************************
 ** Function:       winOrBlock
 ** Description:    Checks to see if any user has 2 of 3 of any winning combo.  Sets move to 3rd
 **                 number in combo if user does, otherwise returns -1.  This allows the game to
 **                 first check and see if the computer can win, and then block any potential wins
 ** Input:          char arr[]      || 9 element array with pieces marked
 **                 char testChar   || sets which piece is tested (run twice with 'O' then 'X'
 ** Output:         int (return)    || move if needed, -1 if not
 *************************************************************************************************/
int TicTacToe::winOrBlock(char arr[],char testChar){
    int possible[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{7,5,3}};

    for ( int i = 0 ; i <= 7 ; i++ ) {  //Winner
        int threeValue = 0, move = 0; //reset value
        for ( int j = 0 ; j <=2 ; j++ ) {
            if (arr[(possible[i][j])-1] == testChar) {   //checks if player has piece in solution
                threeValue++;   //player has piece in solution
            }   //end if
            else {
                move = possible[i][j];      //if player has two pieces in this solution,
                                            //this will be the blocking move, else no purpose
            }   //end else/conditional
        }
        if (threeValue == 2 && arr[move-1] != 'X' && arr[move-1] != 'O') {  //need to block
            return move;        //return the blocking move
        }   //end if/conditional
    }   //end for loop, no blocks need to be made

    return -1;
}

/**************************************************************************************************
 ** Function:       randomMove
 ** Description:    Makes a random move (checks for availability)
 ** Input:          char arr[]      || 9 element array with pieces marked
 ** Output:         int (return)    || returns move
 *************************************************************************************************/
int TicTacToe::randomMove(char arr[]){
    int compMove = 0;

    do  //create random number, test against board, run till move available
    {
        compMove = rand_int(1,9);
    } while (compMove != arr[compMove-1] - '0');    //forces new move if space taken

    return compMove;
}

/**************************************************************************************************
 ** Function:       makeMove
 ** Description:    Places correct piece into correct spot in board array
 ** Input:          char arr[]  || 9 element array that holds each board value
 **                 int move    || the move
 **                 char piece  || piece to place at move location
 ** Output:         none
 *************************************************************************************************/
void TicTacToe::makeMove(char arr[], int move, char piece){
    arr[move-1] = piece; //make the move
    printBoard(arr);     //print out board
}

/**************************************************************************************************
 ** Function:       getValidInput
 ** Description:    Catches non-valid entries, cleans up on error and requests new input
 ** Input:          int &input || input (by ref) to test
 ** Output:         none
 *************************************************************************************************/
void TicTacToe::getValidInput(int &input){
    while(!(std::cin >> input)){    //catches non valid entries
        std::cin.clear();           //clear stream
        while(std::cin.get()!= '\n'){    //ignores errors before \n escape char
            continue;
        }
        std::cout << "Please enter a valid input: ";
    }
}

/**************************************************************************************************
 ** Function:       checkVictory
 ** Description:    Brute force check for victory
 ** Input:          char arr[]      || 9 element array with pieces marked
 ** Output:         bool (return)   || returns true victory, else false
 *************************************************************************************************/
bool TicTacToe::checkVictory(char arr[]){
    int pos1[8] = {1,4,7,1,2,3,1,7}, pos2[8] = {2,5,8,4,5,6,5,5}, pos3[8] = {3,6,9,7,8,9,9,3};

    for ( int i = 0 ; i <= 7 ; i++ ){
        if ( arr[pos1[i]-1] == 'X' && arr[pos2[i]-1] == 'X' && arr[pos3[i]-1] == 'X' ){
            return true;
        }   //end if
        else if ( arr[pos1[i]-1] == 'O' && arr[pos2[i]-1] == 'O' && arr[pos3[i]-1] == 'O' ){
            return true;
        }   //end else if/conditional
    }   //end for loop (i)
    return false;
}

/**************************************************************************************************
 ** Function:       rand_int
 ** Description:    Given a high and low input, returns psuedo random number between
 ** Input:          int iMin        || low value for random
 **                 int iMax        || high value for random
 ** Output:         int (return)    || returns pseudo random number
 *************************************************************************************************/
int TicTacToe::rand_int(int iMin, int iMax)
{
    srand(time(NULL));
    return (rand() % iMax + iMin);
}
