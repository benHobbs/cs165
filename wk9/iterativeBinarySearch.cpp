/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   3/6/2014
 ** Lab/Project#:   Excersise 16, Problem 1
 ** Filename:       iterativeBinarySearch.cpp
 ** Overview: 	    This program contains a template for the iterative binary search algorithm
 **                 from display 13.8 in the book.
***************************************************************************************************/
#include <iostream>


/**************************************************************************************************
 ** Function:       binarySearch
 ** Description:    Iterative binary search function.
 ** Precondition:   Array must be sorted, and of comparable types. ie int, double, char, etc.
 ** Postcondition:  Returns true (and index by ref) if key is in array of objects.
 *************************************************************************************************/
template <typename T>
bool binarySearch(T a[], int last, T key, int& location){
    int first = 0, mid;

    while(first <= last){
        mid = (first + last) / 2;

        if (key == a[mid]){
            location = mid;
            return true;
        }
        else if (key < a[mid]){ last = mid - 1; }
        else if (key > a[mid]){ first = mid + 1; }
    }
    return false;
}

int main()
{
    int a[10] = {1,3,4,6,8,9,11,45,50,1001}, loc = 0;

    char b[5] = {'a','b','c','d','e'};

    //char test
    bool found = binarySearch(b,4,'e',loc);
    if (found){
        std::cout << "Item found at position " << loc << "." << std::endl;
    }
    else{ std::cout << "Item not found." << std::endl; }

    //int test
    found = binarySearch(a,9,50,loc);
    if (found){
        std::cout << "Item found at position " << loc << "." << std::endl;
    }
    else{ std::cout << "Item not found." << std::endl; }

    return 0;
}

