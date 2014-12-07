/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/10/2014
 ** Lab/Project#:   Ex. 10 Problem 4
 ** Filename:       sum3and5mult.cpp
 ** Overview: 	    A function that returns the sum of all the multiples of 3 or 5 below 1000.
 ** Input:  		none
 ** Output: 		none
***************************************************************************************************/
#include <iostream>

int sum(int low, int high);

int main(){
    std::cout << sum(0,1000) << std::endl;

    return 0;
}


/**************************************************************************************************
 ** Function:       arrays (constructor)
 ** Description:    Sums multiples of 3 and 5 for low to high values above zero.
 ** Input:          int low     || start value
 **                 int high    || end value (not inclusive)
 ** Output:         int (return)|| sum
 *************************************************************************************************/
int sum(int low, int high){
    int sum = 0;
    for (int i = low ; i < high ; i++){
        if (i % 3 == 0 || i % 5 == 0){    //multiple of 3 or 5
            sum += i;
        }
    }
    return sum;
}
