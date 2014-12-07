/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/10/2014
 ** Lab/Project#:   Ex. 10 Problem 3
 ** Filename:       ex2.cpp
 ** Overview: 	    A class that has three 10 X 10 arrays.  Member functions set the initial values
 **                 and then place the product of the first two arrays into the third array.
 ** Input:  		none
 ** Output: 		prints out 3 columns, 1 for each array
***************************************************************************************************/
#include <iostream>

class ArrayHandler
{
public:
    //member functions
    ArrayHandler();
    void matrixProduct();
    void printArrays();

private:
    //variables
    int arr_1[10][10];
    int arr_2[10][10];
    int arr_3[10][10];
};


/**************************************************************************************************
 ** Function:       arrays (constructor)
 ** Description:    Sets initial array values
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
ArrayHandler::ArrayHandler(){
    for ( int i = 0 ; i < 10 ; i++ ){
        for ( int j = 0 ; j < 10 ; j++ ){
            arr_1[i][j] = (i*10)+j+1;
            arr_2[i][j] = 101 - ((i*10)+j+1);
            arr_3[i][j] = 0;
        }
    }
}


/**************************************************************************************************
 ** Function:       matrixProduct
 ** Description:    Sets the value of the third array to the product of the first two arrays
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void ArrayHandler::matrixProduct(){
    for ( int i = 0 ; i < 10 ; i++ ){
        for ( int j = 0 ; j < 10 ; j++ ){
            arr_3[i][j] = arr_1[i][j] * arr_2[i][j];
        }
    }
}


/**************************************************************************************************
 ** Function:       printArray
 ** Description:    Prints the arrays out as columns
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void ArrayHandler::printArrays(){
    for ( int i = 0 ; i < 10 ; i++ ){
        for ( int j = 0 ; j < 10 ; j++ ){
            std::cout << arr_1[i][j] << ":" << arr_2[i][j] << ":" << arr_3[i][j] << std::endl;
        }
    }
}


int main()
{
    ArrayHandler a;

    a.matrixProduct();
    a.printArrays();

    return 0;
}
