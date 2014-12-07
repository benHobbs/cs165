/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/5/2014
 ** Lab/Project#:   Ex. 8 Problem 4
 ** Filename:       structsAndPointers.cpp
 ** Overview: 	    This program does the plethora of disjointed steps in problem 4.  They are in
 **                 order.
 **
 ** Input:  		None
 ** Output: 		Tests for each part of the problem
 ** References:		...
***************************************************************************************************/

#include <iostream>	    //std::cout, std::cin
#include <string>	    //std::string

struct person
{
    std::string name;
};

int main()
{
    person friend1, *ptr_friend1;
    ptr_friend1 = &friend1;

    std::cout << "Prove pointer and var have same address: "
              << &friend1 << ":" << ptr_friend1 << std::endl;

    ptr_friend1 -> name = "Steve";  //assign value to friend1.name using pointer
    std::cout << friend1.name << std::endl << std::endl; //prove via output

    person friends[3];  //create array of friends
    std::string friendNames[3] = {"Steve","Martin","Toshiyuki"};
    for (int i = 0 ; i < 3 ; i++ )  //fill array
    {
        friends[i].name = friendNames[i];
        std::cout << friends[i].name << std::endl;
    }


    person *ptr_friends = new person[3];  //create array of friends
    for (int i = 0 ; i < 3 ; i++ )  //fill array
    {
        ptr_friends[i].name = friendNames[i];  //assign value to friend1.name using pointer
        std::cout << ptr_friends[i].name << std::endl;
    }

    return 0;
}
