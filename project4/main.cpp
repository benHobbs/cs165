/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/6/2014
 ** Lab/Project#:   Project 4
 ** Filename:       gameStation.cpp
 ** Overview: 	    This program will allow the user (through a nicely displayed menu) to choose
 **                 a game to play.  Once finished, the user can choose to play another or exit.
 **                     i.      Number Guess
 **                     ii.     Word Guess
 **                     iii.    Phrase Guess
 **                     iv.     Tic Tac Toe
 ** Input:  		none
 ** Output: 		none
 ** References:     http://www.tutorialspoint.com/cplusplus/cpp_class_member_functions.htm
 **
***************************************************************************************************/

#include <iostream>	        //std::cout, std::cin
#include <string>	        //std::string
#include "NumberGuess.h"
#include "NumberGuess.cpp"
#include "WordGuess.h"
#include "WordGuess.cpp"
#include "PhraseGuess.h"
#include "PhraseGuess.cpp"
#include "TicTacToe.h"
#include "TicTacToe.cpp"

void printMenu();
void makeSpace(int rows);

int main()
{
    char userInput; //holds user input in menu

    do{     //run game mene
        makeSpace(50);
        printMenu();    //print the menu
        std::cin >> userInput;
        switch(userInput){
        case 'n':{
            makeSpace(50);
            NumberGuess game;
            game.playGame();
            break;}
        case 'w':{
            makeSpace(50);
            WordGuess game;
            game.playGame();
            break;}
        case 'p':{
            makeSpace(50);
            PhraseGuess game;
            game.playGame();
            break;}
        case 't':{
            makeSpace(50);
            TicTacToe game;
            game.playGame();
            break;}
        case 'e':
            return 0;
        default:
            std::cout << "            Invalid...Game Choice:";
        }
    } while (userInput != 'e');

    return 0;
}

/**************************************************************************************************
 ** Function:       printMenu
 ** Description:    Prints game station menu
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void printMenu(){
    std::cout << " *****************************************\n";
    std::cout << " *****************************************\n";
    std::cout << " **                                     **\n";
    std::cout << " **     Welcome to the Game Station     **\n";
    std::cout << " **                                     **\n";
    std::cout << " **          [n]umber guess             **\n";
    std::cout << " **          [w]ord guess               **\n";
    std::cout << " **          [p]hrase guess             **\n";
    std::cout << " **          [t]ic tac toe              **\n";
    std::cout << " **                                     **\n";
    std::cout << " **          [e]xit                     **\n";
    std::cout << " **                                     **\n";
    std::cout << " *****************************************\n";
    std::cout << " *****************************************\n\n";
    std::cout << "             Game Choice: ";
}

/**************************************************************************************************
 ** Function:       makeSpace
 ** Description:    Creates rows number of rows of empty space.
 ** Input:          int rows    || number of empty rows to create
 ** Output:         none
 *************************************************************************************************/
void makeSpace(int rows){
    for ( int i = 0 ; i < rows ; i++ ){
        std::cout << std::endl;}
}
