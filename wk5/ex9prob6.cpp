/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/6/2014
 ** Lab/Project#:   Ex. 9 Problem 6
 ** Filename:       classesAndPointers.cpp
 ** Overview: 	    This program does all of the steps in problem 6 in order.
 **
 ** Input:  		None
 ** Output: 		Tests for each part of the problem
 ** References:		...
***************************************************************************************************/

#include <iostream>	    //std::cout, std::cin
#include <string>	    //std::string

class Person
{
public:
    std::string name;
};

int main()
{
    Person friend1, *ptr_friend1;
    ptr_friend1 = &friend1;

    std::cout << "Prove pointer and object have same address: "
              << &friend1 << ":" << ptr_friend1 << std::endl;

    ptr_friend1 -> name = "Steve";  //assign value to friend1.name using pointer
    std::cout << friend1.name << std::endl << std::endl; //prove via output

    Person friends[3];  //create array of friends
    std::string friendNames[3] = {"Steve","Martin","Toshiyuki"};
    for (int i = 0 ; i < 3 ; i++ )  //fill array
    {
        friends[i].name = friendNames[i];
        std::cout << friends[i].name << std::endl;
    }

    Person *ptr_friends = new Person[3];  //create array of friends
    for (int i = 0 ; i < 3 ; i++ )  //fill array
    {
        ptr_friends[i].name = friendNames[i];  //assign value to friend1.name using pointer
        std::cout << ptr_friends[i].name << std::endl;
    }

    return 0;
}
