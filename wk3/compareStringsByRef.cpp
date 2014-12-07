/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/20/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Excercise 5 Problem 2
** 	Filename: compareStringsByRef.cpp
**
** 	Overview: 	This program uses a function to compare two strings.
**
** 	Input:		str_1 and str_2
**
** 	Output:		True/False (the strings are the same or not)
**
**  References: http://www.cplusplus.com/reference/string/string/compare/
**
**  std::cin.ignore(50,'\n'); //clear buffer
***************************************************************************************************/
#include <iostream>
#include <string>

int str_comp(std::string& str1, std::string& str2);   //proto function

int main()
{
    std::string str1, str2;

    std::cout << "We are going to compare two sentences.\nPlease enter your first sentence: ";
    std::getline( std::cin , str1 );    //collect the first string

    std::cout << "Please enter your second sentence: ";
    std::getline( std::cin , str2 );    //collect the second string
    if ( str_comp( str1 , str2 ) == 0 ) //calls function, if returns 0, then strings are same
    {
        std::cout << "\nThese sentences are exactly the same.\n\n";
    }
    else
    {
        std::cout << "\nThese sentences are NOT the same.\n\n";
    }

    return 0;
}

int str_comp(std::string& str1, std::string& str2)    //compares two strings, returns 0 if same
{
    return ( str1.compare( str2 ));
}
