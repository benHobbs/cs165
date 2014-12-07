/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   3/6/2014
 ** Lab/Project#:   Exercise 16, Problem 3
 ** Filename:       insertionSort.cpp
 ** Overview: 	    This program contains a template for the insertion sort algorithm.
***************************************************************************************************/
#include <iostream>
/**************************************************************************************************
 ** Function:       insertionSort(int a[], int len)
 ** Description:    Insertion Sort Function.
 ** Postcondition:  Returns sorted array
 *************************************************************************************************/
void insertionSort(int a[], int len){
    int i, j ,temp;

    for (i = 1; i < len; i++){  //loops through the array
        j = i;  //take current value

        while (j > 0 && a[j - 1] > a[j]){   //while cur el is smaller than previous,
            temp = a[j];                    //swap current value backwards
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }//end of while loop
    }//end for loop i
}

/**************************************************************************************************
 ** Function:       insertionSort(int a[], int len)
 ** Description:    Insertion Sort Function.  Template version.
 ** Postcondition:  Returns sorted array
 *************************************************************************************************/
template <typename T>
void insertionSort(T a[], int len){
    int i;
    T j ,temp;

    for (i = 1; i < len; i++){  //loops through the array
        j = i;  //take current value

        while (j > 0 && a[j-1] > a[j]){   //while cur el is smaller than previous,
            temp = a[j];                    //swap current value backwards
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }//end of while loop
    }//end for loop i
}


int main()
{
    int a[10] = {3,2,8,5,4,6,9,10,19,11};
    char b[10] = {'a','b','t','g','p','a','r','n','m','x'};

    for(int i = 0 ; i < 10 ; i++ ){
	std::cout << b[i] << " ";
    }

    std::cout << std::endl;

    insertionSort(b,10);

    for(int i = 0 ; i < 10 ; i++){
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

}
