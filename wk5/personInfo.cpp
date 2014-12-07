/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/4/2014
 ** Lab/Project#:   Ex. 8 Problem 1
 ** Filename:       personInfo.cpp
 ** Overview: 	    This program creates a struct (person) and lets the user enter information for
 **                 that struct.
 ** Input:  		None
 ** Output: 		Info from struct
 ** References:		...
***************************************************************************************************/

#include <iostream>	    //std::cout, std::cin

struct Person   //struct to hold information for person
{
    char name[11];  //10+1
    int age;
};

void getInfo(Person &aPerson);   //returns filled struct Person
void getValidInput(int &input, std::string errorMsg = "Please enter a valid input: ");

int main()
{
    Person someDude;

    getInfo(someDude);

    std::cout << "Personal Information\nName: " << someDude.name << "\nAge: " << someDude.age
              << std::endl;

    return 0;
}


/**************************************************************************************************
 ** Function:       getInfo
 ** Description:    Accepts Person struct, asks for user input, returns struct by reference
 ** Input:          struct (Person)
 ** Output:         struct (Person)
 *************************************************************************************************/

void getInfo(Person &aPerson)
{
    std::cout << "Personal Information Collector\n\nPlease enter the persons name: ";
    std::cin.getline(aPerson.name,10);
    std::cout << "Please enter the persons age: ";
    getValidInput(aPerson.age);
}


/**************************************************************************************************
 ** Function:       getValidInput
 ** Description:    takes an input and checks to make sure it is a valid entry
 ** Input:          input (this type can be changed
 ** Output:         struct (Person)
 *************************************************************************************************/

void getValidInput(int &input, std::string errorMsg)
                                    //cleans up on error and requests new input
{
        while(!(std::cin >> input))                         //catches non int entries
        {
            std::cin.clear();               //clear stream
            while(std::cin.get()!= '\n')    //ignores errors before \n escape char
            {
                continue;
            }
            std::cout << errorMsg;
        }
}

