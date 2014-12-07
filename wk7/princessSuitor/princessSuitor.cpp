/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/18/2014
 ** Lab/Project#:   Ex. 12 Problem 3
 ** Filename:       princessSuitor.cpp
 ** Overview: 	    For only a nominal fee, my program will get you (the illustrious prince, duke,
 **                 baron, or mere peasant, the hand of the most lovely lady of your imagination*.
 **
 **                 *Assuming she uses a rather odd set of rules to choose her companion.
 ** Input:  		none
 ** Output: 		none
***************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>

class SuitorCounter
{
public:
    SuitorCounter();            //constructor
    void run();                 //runs the 'program'
    void printChoiceSpot();     //prints the winning spot

private:
    void buildVector();  //sets up vector based on constructor obtained # of suitors, called from const
    void printVector();     //unused

    int numSuitors;     //number of suitors
    int name_length;    //length of princesses' name (for elimination step determination

    std::string princess_name;  //princesses name

    std::vector<int> v; //vector to hold suitors
};

/**************************************************************************************************
 ** Function:       SuitorCounter (constructor)
 ** Description:    Gets the princesses' name and how many competitors we shall be competing
 **                 against.
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
SuitorCounter::SuitorCounter(){
    std::cout << "Please enter the princesses' name: ";
    std::cin >> princess_name;

    name_length = princess_name.length();   //sets length of name

    std::cout << "How many suitors are wooing said fair lass? ";
    std::cin >> numSuitors;

    buildVector();
}

/**************************************************************************************************
 ** Function:       buildVector
 ** Description:    Adds the appropriate number of suitors to the vector.
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void SuitorCounter::buildVector(){
    for (int i = 0 ; i < numSuitors ; i++ ){
        v.push_back(i+1);
    }
}

/**************************************************************************************************
 ** Function:       run
 ** Description:    This function runs a while loop, with a nested for loop that iterates through
 **                 the suitor vector.  When the counter is divisible by the princesses' name (len)
 **                 that suitor is eliminated.
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void SuitorCounter::run(){
    int vCounter = 0;   //sets the position to the start of the vector
    while (v.size()>1){
        for (auto i = v.begin() ; i != v.end() ; i++ ){ //runs through the vector
            vCounter++;
            if (vCounter % name_length == 0){
                v.erase(v.begin() + std::distance(v.begin(), i));
                i--;    //move iterator back to correct spot
            }
        }
    }
}

/**************************************************************************************************
 ** Function:       printVector
 ** Description:    Prints out vector from class.  Not used in this particular run of the program.
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void SuitorCounter::printVector(){
    for (auto i = v.begin() ; i != v.end() ; i++ ){
        std::cout << std::distance(v.begin(), i) << ":" << *i << std::endl;
    }
}

/**************************************************************************************************
 ** Function:       printChoiceSpot
 ** Description:    Prints out the spot where the suitor should stand if they want to win.
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void SuitorCounter::printChoiceSpot(){
    std::cout << "In order to win with the conditions given above, you should stand at spot *"
              << v[0] << "*.\nGood luck." << std::endl;
}

int main()
{
    SuitorCounter eliminator;   //create SuitorCounter named eliminator

    eliminator.run();               //runs the program
    eliminator.printChoiceSpot();   //prints out the choice spot for the suitor

    return 0;
}
