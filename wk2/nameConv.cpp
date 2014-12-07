/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/17/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Week 3 9b
** 	Filename: nameConv.cpp
**
** 	Overview: 	Program takes a name as entered and formats it
**
** 	Input:		User Input (str) : Mary Average User
**				                   Mary A. User
**				                   Mary User
**
** 	Output:		Formatted Name   : User, Mary A.
**                                 User, Mary A.
**                                 User, Mary
**
**  References: Discussion with Joshua Smith & Anthony Clark
**              http://www.cplusplus.com/reference/string/string/
**
***************************************************************************************************/
#include <iostream>
#include <string>

int main()
{
    int firstSpace = 0, secondSpace = 0;
    std::string string_UserInput;
    std::string strFirstName, strMiddleName, strLastName;

    std::cout << "Please enter the FULL name:\n";
    std::getline( std::cin , string_UserInput );

    firstSpace = string_UserInput.find_first_of(" ");

    strFirstName = string_UserInput.substr(0, firstSpace);
    string_UserInput = string_UserInput.substr(firstSpace + 1, string_UserInput.length());

    secondSpace = string_UserInput.find_first_of(" ");

    if ( secondSpace != -1 )    //-1 means second space, so no middle name
    {
        strMiddleName = string_UserInput.substr(0, secondSpace);
        string_UserInput = string_UserInput.substr(secondSpace + 1, string_UserInput.length());
        strLastName = string_UserInput;
        std::cout << strLastName << ", " << strFirstName << " " << strMiddleName.at(0) << ".\n";
    }
    else if ( secondSpace == -1 )   //no second space
    {
        strLastName = string_UserInput;
        std::cout << strLastName << ", " << strFirstName << std::endl;
    }

    return 0;
}
