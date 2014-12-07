/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/10/2014
 ** Lab/Project#:   Ex. 11 Problem 2
 ** Filename:       productID.cpp
 ** Overview: 	    Program runs getProductsID function and handles error throws.
 ** Input:  		none
 ** Output: 		none
 ** Notes:          Initially I set this up to run without the function handleGetProductID, so all
 **                 of the function calls were in one try statement.  But the result, that it only
 **                 printed out the valid productIDs before it hit an error, was unsatisfactory to
 **                 me.  Thus creation of the handler function.  In a realistic setting, ie one
 **                 where the user needs to get a list of the product ids, I would probably create
 **                 an array in main to hold the ids, and then pass it to the handler.  The handler
 **                 would print out each successive operation and then add the productID (if it
 **                 returned an int) to the array, so the nums could be used elsewhere.  In terms of
 **                 testing, this project worked pretty much the way I assumed it would.  It did
 **                 however, take me quite awhile to figure out how to throw a string exception.
 **                 So many thanks to cplusplus.com yet again.
***************************************************************************************************/
#include <iostream>
#include <string>

int getProductID(int ids[], std::string names[], int numProducts,
                            std::string target) throw ( std::string );
void handleGetProductID(int ids[], std::string names[], int numProducts, std::string target);

int main()  // Sample code to test the getProductID function
{
    int productIds[] = {4,5,8,10,13};
    std::string products[] = {"computer","flash drive","mouse","printer","camera"};

    handleGetProductID(productIds,products,5,"mouse");
    handleGetProductID(productIds,products,5,"laptop");
    handleGetProductID(productIds,products,5,"camera");

    return 0;
}

/**************************************************************************************************
 ** Function:       handleGetProductsID
 ** Description:    Function takes two arrays, array length, and target product.  Passes to
 **                 getProductID function.  Handles any thrown error.  In actuality would probably
 **                 require another array to store successful searches.
 ** Input:          int ids[]           || array of product IDs
 **                 std::string names[] || array of products
 **                 int numProducts     || number of products in arrays
 **                 std::string target  || item to be searched for
 ** Output:         none
 *************************************************************************************************/
void handleGetProductID(int ids[], std::string names[], int numProducts, std::string target){
    try
    {
        std::cout << getProductID(ids,names,numProducts,target) << std::endl;
    }
    catch ( std::string thrownError )
    {
        std::cout << "The item -" << thrownError << "- is not an item in the product list."
                  << "  Stop Function." << std::endl;
    }
}

/**************************************************************************************************
 ** Function:       getProductsID
 ** Description:    Function takes two arrays, array length, and target product.  Searches product
 **                 array and if match found, product ID returned.  Exception thrown if no product.
 ** Input:          int ids[]           || array of product IDs
 **                 std::string names[] || array of products
 **                 int numProducts     || number of products in arrays
 **                 std::string target  || item to be searched for
 ** Output:         int (return)        || Product ID if viable
 ** Exception:      std::string         || target
 *************************************************************************************************/
int getProductID(int ids[], std::string names[], int numProducts, std::string target) throw ( std::string ){
        for (int i = 0 ; i < numProducts ; i++ ){
            if ( names[i] == target ){
                return ids[i];
            }
        }
        throw ( target );
}
