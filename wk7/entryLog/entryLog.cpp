/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/18/2014
 ** Lab/Project#:   Ex. 12 Problem 2
 ** Filename:       consignmentInventory.cpp
 ** Overview: 	    This program lets the user log visitors into a building by suppling name and
 **                 room number.  Runs until exit.
 ** Input:  		none
 ** Output: 		none
 ** References:     http://www.dreamincode.net/forums/topic/63358-store-class-objects-in-vector/
***************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>

class Person
{
public:
    Person();       //constructor
    void getInfo(); //Print name and room number
    void setName(std::string personName){ name = personName; }
    void setRoom(int roomNumber){ roomNum = roomNumber; }

private:
    std::string name;
    int roomNum;
};

/**************************************************************************************************
 ** Function:       Item (constructor)
 ** Description:    Intentionally left blank.
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
Person::Person(){ /* Intentionally left blank */}

/**************************************************************************************************
 ** Function:       getInfo
 ** Description:    Print name and room number.
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void Person::getInfo(){
    std::cout << name << ", " << roomNum << std::endl;
}

/**************************************************************************************************
 ** Main ******************************************************************************************
 *************************************************************************************************/

void newPerson(std::vector<Person>& userLog);   //add new visitor
void clearIOStream();                           //clear iostream buffer
void getValidInput(int &input);                 //int version

int main()
{
    std::vector<Person> userLog;
    char userInput; //holds user input in menu

    do{
        for (int rows = 0 ; rows < 50 ; rows++ ){ std::cout << std::endl; } //makes some space

        std::cout << " ----------Visitor Log----------\n\n";
        std::cout << " Name, Room #\n\n";

        for ( auto i = userLog.begin() ; i != userLog.end() ; i++ ){    //print userLog Vector
            std::cout << " ";
            i -> getInfo();
        }

        std::cout << "\n\n[l]og new visitor; [e]xit program: ";
        std::cin >> userInput;
        switch(userInput){
        case 'l':{
            newPerson(userLog);
            break;}
        case 'e':
            return 0;
        default:
            std::cout << " Invalid Entry\n\n\n";
            clearIOStream();    //clear iostream buffer
        }
    } while (userInput != 'e');

    return 0;
}


/**************************************************************************************************
 ** Function:       printMenu
 ** Description:    Prints Inventory System Menu
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void newPerson(std::vector<Person>& userLog){
    std::string name, userInput;
    int roomNumber = 0;

    Person *person1;

    clearIOStream();                    //clear iostream buffer
    std::cout << "\n\nEnter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter room number: ";
    getValidInput(roomNumber);

    person1 = new Person;
    person1 -> setName(name);
    person1 -> setRoom(roomNumber);

    userLog.push_back(*person1);

    return;
}


/**************************************************************************************************
 ** Function:       clearIOStream
 ** Description:    Clears the io stream
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void clearIOStream(){
    std::cin.clear();                   //clear stream
    while(std::cin.get()!= '\n'){       //ignores errors before \n escape char
        continue;
    }
}


/**************************************************************************************************
 ** Function:       getValidInput
 ** Description:    Catches non-valid entries, cleans up on error and requests new input
 ** Input:          int &input || input (by ref) to test
 ** Output:         none
 *************************************************************************************************/
void getValidInput(int &input){
    while(!(std::cin >> input)){    //catches non valid entries
        std::cin.clear();           //clear stream
        while(std::cin.get()!= '\n'){    //ignores errors before \n escape char
            continue;
        }
        std::cout << "\tPlease enter a valid input: ";
    }
}
