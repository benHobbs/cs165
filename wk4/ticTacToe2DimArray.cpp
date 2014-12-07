/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/28/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Ex. 6 Problem 4 (p234)
** 	Filename:   ticTacToe2d.cpp
**
** 	Overview: 	This program allows two users to play tic tac toe.  Two dimensional array version.
**
** 	Input:      Users input positions (1-9)
**
** 	Output:		Updated Board
**
**  References:	http://en.wikipedia.org/wiki/Modulo_operation
**
***************************************************************************************************/
#include <iostream>

void printBoard(char arr[][3]);
bool is_odd(int n);
void getValidInput(int &input);

int main()
{
    char cExit;

    do  //do_while used to run game again
    {

        char boardArrayPrep[9] = {'1','2','3','4','5','6','7','8','9'}; //cause I be lazy
        char boardArray[3][3];  //declare 2d array

        for ( int i = 0 ; i < 3 ; i++ ) //init 2d array
        {
            for ( int j = 0 ; j < 3 ; j++ )
            {
                boardArray[i][j] = boardArrayPrep[(i*3)+j];
            }
        }

        std::cout << "\nTic Tac Toe\nLegit Version\n\n";                //print intro

        printBoard(boardArray);                                         //print board

        for ( int i = 0 ; i < 9 ; i++ )     //game loop (runs for 9 moves or until 0 is entered)
        {
            int move, activePlayer;
            char piece;

            if (is_odd(i) != true )    //set info for player 1
            {
                activePlayer = 1;
                piece = 'X';
            }
            else    //set info for player 2
            {
                activePlayer = 2;
                piece = 'O';
            }   //end conditional

            std::cout << "\nP" << activePlayer << ":  Please choose a move (0 exits): ";
            getValidInput(move);        //get int as input

            if ( move == 0 )    //exit this round of the game
            {
                std::cout << "You have exited the game.\n\n";
                break;
            }
            else if ( ! ( move < 1 || move > 9 ) )  //a valid move
            {
                boardArray[ (move - 1 )  / 3 ][ ( ( move - 1 ) % 3 ) ] = piece; //make the move
                           //move - 1 / len       ( move - 1 ) % len )  for dynamic version
                printBoard(boardArray);     //print out board
            }
            else    //invalid entry
            {
                std::cout << "You have entered an invalid square...Let's try that again.\n\n";
                i--;
            }
        }   //end for loop, game is over

        std::cout << "\n\nPlay again?\n(y/n): ";    //exit sequence
        std::cin >> cExit;
    } while ( cExit != 'n' );   //end do_while loop, used to run game again

    return 0;
}

void printBoard(char arr[][3]) //print out the board
{
    std::cout << std::endl;
    for ( int i = 0 ; i <= 2 ; i++ )
    {
        for ( int j = 0 ; j <= 2 ; j++ )
        {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
}

bool is_odd(int n)
{
    return n % 2 != 0;
}

void getValidInput(int &input)      //takes a variable and catches non-valid entries
                                    //cleans up on error and requests new input
{
    while(!(std::cin >> input))                         //catches non int entries
    {
        std::cin.clear();               //clear stream
        while(std::cin.get()!= '\n')    //ignores errors before \n escape char
        {
            continue;
        }
        std::cout << "Please enter a valid input: ";
    }
}

