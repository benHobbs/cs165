/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/28/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Ex. 6 Problem 4 (p234)
** 	Filename: tttd1.cpp
**
** 	Overview: 	This program allows two users to play tic tac toe.  One dimensional array version.
**
** 	Input:      Users input positions (1-9)
**
** 	Output:		Updated Board
**              Outputs victory
**
**  References:	http://en.wikipedia.org/wiki/Modulo_operation
**
***************************************************************************************************/
#include <iostream>

void printBoard(char arr[]);
bool is_odd(int n);
void getValidInput(int &input);
bool checkVictory(char arr[]);

int main()
{
    char cExit;

    do  //do_while used to run game again
    {

        char boardArray[9] = {'1','2','3','4','5','6','7','8','9'};     //declare array

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
                boardArray[move-1] = piece; //make the move
                printBoard(boardArray);     //print out board
                if ( checkVictory(boardArray) == true )   //check for victory, if true victory
                {
                    std::cout << "\n\n\nPlayer " << activePlayer << " is victorious...Congrats.";
                    break;
                }
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

void printBoard(char arr[]) //print out the board
{
    std::cout << std::endl;
    for ( int j = 0 ; j < 3 ; j++ )
    {
        for ( int i = 0 ; i < 3 ; i++ )
        {
            std::cout << arr[(j*3)+i];
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

bool checkVictory(char arr[])
{
    int pos1[8] = {1,4,7,1,2,3,1,7};
    int pos2[8] = {2,5,8,4,5,6,5,5};
    int pos3[8] = {3,6,9,7,8,9,9,3};

    for ( int i = 0 ; i <= 7 ; i++ )
    {
        if ( arr[pos1[i]-1] == 'X' && arr[pos2[i]-1] == 'X' && arr[pos3[i]-1] == 'X' )
        {
            return true;
        }
        else if ( arr[pos1[i]-1] == 'O' && arr[pos2[i]-1] == 'O' && arr[pos3[i]-1] == 'O' )
        {
            return true;
        }
    }
    return false;
}
