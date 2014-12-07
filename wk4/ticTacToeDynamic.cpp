/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/31/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Ex. 7 Problem 4 (p234)
** 	Filename:   ticTacToeDynamicVersion.cpp
**
** 	Overview: 	This program allows two users to play tic tac toe.  Dynamic array version.  Users
**              can choose the size of the board
**
** 	Input:      Users input positions (column row)
**
** 	Output:		Updated Board
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin
#include <math.h>   //pow

void printBoard(int len, char ** arr);
bool is_odd(int n);
void createDynamicArray(int h, int l);

int main()
{
    char cExit;

    do  //do_while used to run game again
    {
        int len = 0;    //length of dynamic array

        std::cout << "\nTic Tac Toe\nLegit Version\n\n";    //print intro

        std::cout << "How big do you want your board (give width as an int)? ";
        std::cin >> len;

        int height = len, width = len;

        char **boardArray = new char*[height];    //declare first dynamic array
        for ( int i = 0 ; i < height ; i++ )    //declare each separate array
        {
            boardArray[i] = new char[width];
        }

        for ( int i = 0 ; i < height ; i++ )    //fill array
        {
            for ( int j = 0 ; j < width ; j++)
            {
                boardArray[i][j] = '-';
            }
        }

        printBoard(len, boardArray);

        for ( int i = 0 ; i < pow(len,2) ; i++ )     //game loop (runs for 9 moves or until 0 is entered)
        {
            int move, activePlayer;
            int row = 0, column = 0;
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

            std::cout << "\nP" << activePlayer << ":  Please choose a move (column row) (0 0 exits): ";
            //getValidInput(move);        //get int as input
            std::cin >> row >> column;

            if ( row + column == 0 )    //exit this round of the game
            {
                std::cout << "You have exited the game.\n\n";
                break;
            }
            else if ( ( row > 0 && row < len + 1 ) && (column > 0 && column < len + 1) )  //a valid move
            {
                boardArray[ column -1 ][ row -1 ] = piece; //make the move
                printBoard(len, boardArray);     //print out board
            }
            else    //invalid entry
            {
                std::cout << "You have entered an invalid square...Let's try that again.\n\n";
                i--;
            }
        }   //end for loop, game is over

        for ( int i = 0 ; i < height ; i++ )    //free up memory by deleting arrays
        {
            delete boardArray[i];
        }
        delete [] boardArray;

        std::cout << "\n\nPlay again?\n(y/n): ";    //exit sequence
        std::cin >> cExit;
    } while ( cExit != 'n' );   //end do_while loop, used to run game again

    return 0;
}

void printBoard(int len, char ** arr)   //print board
{
    std::cout << std::endl;
    for ( int i = 0 ; i <= len ; i++ )
    {
        for ( int j = 0 ; j <= len - 1 ; j++ )
        {
            ( i == 0 ) ? std::cout << j + 1 << " ": std::cout << arr[i-1][j] << " ";    //ternary
        }
        std::cout << i << "\n\n";
    }
}

bool is_odd(int n)
{
    return n % 2 != 0;
}
