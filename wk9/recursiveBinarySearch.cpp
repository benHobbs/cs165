/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   3/6/2014
 ** Lab/Project#:   Excersise 16, Problem 2
 ** Filename:       recursiveBinarySearch.cpp
 ** Overview: 	    This program contains a template for the recursive binary search algorithm
 **                 from display 13.7 in the book.
***************************************************************************************************/
#include <iostream>


/**************************************************************************************************
 ** Function:       binarySearchRecursive
 ** Description:    Recursive binary search function.
 ** Precondition:   Array must be sorted, and of comparable types. ie int, double, char, etc.
 ** Postcondition:  By reference | bool found will be true and index will be populated if key is in
 **                 array of objects.
 *************************************************************************************************/
template <typename T>
void binarySearchRecursive(bool &found, T a[],T key, int first, int last, int &location){
    int mid;

    if (first > last)
    {
        found = false;
    }
    else {
        mid = (first + last) / 2;

        if (key == a[mid])
        {
            found = true;
            location = mid;
        }
        else if (key < a[mid])
        {
            binarySearchRecursive(found,a,key,first,mid-1,location);
        }
        else if (key > a[mid])
        {
            binarySearchRecursive(found,a,key,mid+1,last,location);
        }
    }
}

int main()
{
    int a[10] = {1,3,4,6,8,9,11,45,50,1001}, loc = 0;

    char b[5] = {'a','b','c','d','e'};

    //char test
    bool found = false;

    binarySearchRecursive(found,b,'d',0,4,loc);

    if (found){
        std::cout << "Item found at position " << loc << "." << std::endl;
    }
    else{ std::cout << "Item not found." << std::endl; }

    return 0;
}

