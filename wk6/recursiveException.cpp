/**************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/10/2014
 ** Lab/Project#:   Ex. 11 Problem 1
 ** Filename:       recursiveException.cpp
 ** Overview: 	    Calls a recursive function that throws an exception when the requisite number
 **                 of iterations is reached.
 ** Input:  		none
 ** Output: 		none
 ** Notes:			This project asked us to mention if we ended up having to do multiple attempts.
 **					Thus I am noting that once I figured out what the book meant by 'additional
 **					conditions' I got it up and running without having to redesign.  As a side note
 **					the book would be easier to follow if the author wasn't such a pompous fellow.
**************************************************************************************************/
#include <iostream>

void recursiveFunction(int throwLevel, int i);

int main(){
    int throwLevel = 5;	//set the level to throw the exception (0 is main)

    try{	//setup the try
        if (throwLevel != 0 ){	//catch level 0 throw
            recursiveFunction(throwLevel, 0);	//call recursive function
        }	//end if
        else {
            throw throwLevel;
        }	//end else | conditional
    }	//end try
    catch(int throwLevel){
        std::cout << "The error was thrown on level " << throwLevel << ".\n";
    }

    return 0;
}


/**************************************************************************************************
 ** Function:       arrays (constructor)
 ** Description:    Recursive function that throws an exception when throwLevel == the recursive
 **                 counter
 ** Input:          int throwLevel  || level where the exception should be thrown (0) is main.
 **                 int i           || recursive counter
 ** Output:         none
 *************************************************************************************************/
void recursiveFunction(int throwLevel, int i){
    std::cout << i << std::endl;
    if (i == throwLevel){	//catch error condition
        throw throwLevel;	//throw level of error
    }
    else {
        recursiveFunction(throwLevel, ++i);	//recursive step
    }
}
