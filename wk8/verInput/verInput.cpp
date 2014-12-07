/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   3/1/2014
 ** Lab/Project#:   Ex. 14, problem 3
 ** Filename:       fileMerge.cpp
 ** Overview: 	    This program forces the user to enter a valid integer.
***************************************************************************************************/
#include <iostream>
#include <string>
#include <sstream>

int getInput();

int main(int argc, char **argv){
    int validInt = getInput();
    std::cout << validInt << std::endl;
    return 0;
}

/**************************************************************************************************
 ** Function:       getInput
 ** Description:    Uses stringstream to parse in from std::getline(std::cin, string)
 *************************************************************************************************/
int getInput(){
    int integer;
    std::string input;
    std::stringstream ss;

    do{
        std::cout << "Please enter an integer: ";
        std::getline(std::cin, input);
        ss.clear();
        ss.str("");
        ss << input;
    } while (!(ss >> integer));

    return integer;
}
