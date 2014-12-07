/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/17/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Excercise Set 3 Problem 1 a-g
** 	Filename: ex3prob1.cpp
**
** 	Overview: 	This program will create a string variable, use std::cin to get user input for said
**              string, and then print the string, both forward and backwards using 2 for loops.
**              After that the program will tell the user how many letters were contained in the
**              string (also using a for loop).  Finally, the program will ask the user to enter
**              non-standard input and then use the getline function to collect all entered info.,
**              the isalpha function to determine how many letters the user input, and then
**              output the number.
**
** 	Input:		Two strings (one multiword)
**
** 	Output:		Echo the entered string (both forward and backwards) and the number of letters
**              entered (twice).
**
**  References: http://www.cplusplus.com/reference/istream/istream/ignore/  Learned to clear buffer
**              http://www.cplusplus.com/reference/cctype/isalpha/          Learned is alpha func.
**
***************************************************************************************************/
#include <iostream>
#include <string>


int main()
{
    int iLetters = 0;   //how many letters in str
    std::string my_str;

    std::cout << "Please enter some text: " << std::endl;
    std::cin >> my_str;

    for ( int i = 0 ; i < my_str.length() ; i++ )   //print in order
    {
        std::cout << my_str.at(i) << std::endl;
    }

    for ( int i = my_str.length() - 1 ; i >= 0 ; i-- )  //print in reverse
    {
        std::cout << my_str.at(i) << std::endl;
    }

    for ( int i = 0 ; i < my_str.length() ; i++ )   //print nums for each char
    {
        if ( isalpha(int(my_str.at(i))))
        {
            iLetters++;
        }
    }

    std::cout << "There are " << iLetters << " letters in this word.\nNow lets try something"
              << "wild, hit me with letters, numbers, spaces, etc.\n";
    std::cin.ignore(50,'\n'); //clear buffer
    std::getline( std::cin , my_str );

    iLetters = 0;   //reset iletters to zero so we dont double count

    for ( int i = 0 ; i < my_str.length() ; i++ )
    {
        if ( isalpha(int(my_str.at(i))))
        {
            iLetters++;
        }
    }

    std::cout << "There are " << iLetters << " letters in this word." << std::endl;

    return 0;
}
