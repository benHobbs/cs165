/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/18/2014
 ** Lab/Project#:   Ex. 12 Problem 2
 ** Filename:       entryLog.cpp
 ** Overview: 	    This program lets the user log visitors into a building by suppling name and
 **                 room number.  Runs until exit.
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
    std::string getName(int &roomNumber){ roomNumber = roomNum; return name; }
    void setName(std::string personName){ name = personName; }
    void setRoom(int roomNumber){ roomNum = roomNumber; }

private:
    std::string name;
    int roomNum;
};

/**************************************************************************************************
 ** Function:       Item (constructor)
 ** Description:    Intentionally left blank.
 *************************************************************************************************/
Person::Person(){ /* Intentionally left blank */}

/**************************************************************************************************
 ** Function:       getInfo
 ** Description:    Print name and room number.
 *************************************************************************************************/
void Person::getInfo(){
    std::cout << name << ", " << roomNum << std::endl;
}

/**************************************************************************************************
 ** Main ******************************************************************************************
 *************************************************************************************************/

void newPerson(std::vector<Person>& userLog);   //add new visitor
void checkForPerson(std::vector<Person>& userLog);
void removePerson(std::vector<Person>& userLog);
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

        std::cout << "\n\n[l]og visitor; [c]heck for visitor; [r]emove visitor; [e]xit program: ";
        std::cin >> userInput;
        switch(userInput){
        case 'l':{
            newPerson(userLog);
            break;}
        case 'c':{
            checkForPerson(userLog);
            break;}
        case 'r':{
            removePerson(userLog);
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
 ** Function:       newPerson(std::vector<Person>& userLog)
 ** Description:    Adds new Person to the vector storing people.
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
 ** Function:       checkForPerson(std::vector<Person>& userLog)
 ** Description:    Checks to see if a visitor is in the log.
 *************************************************************************************************/
void checkForPerson(std::vector<Person>& userLog){
    std::string name;
    int roomNumber=0;

    clearIOStream();                    //clear iostream buffer

    std::cout << "\n\nEnter Name: ";
    std::getline(std::cin, name);

    for ( auto i = userLog.begin() ; i != userLog.end() ; i++ ){    //print userLog Vector
        std::cout << " ";
        if(name.compare(i -> getName(roomNumber))==0){    //match
            std::cout << "Visitor " << name << " is in room #" << roomNumber << std::endl;
            std::cout << "\n\nPlease hit any key followed by enter to continue:";
            std::cin.get();
            std::cin.ignore();
            return;
        }
    }
    std::cout << "Visitor " << name << " is not in the building." << std::endl;
    std::cout << "\n\nPlease hit any key followed by enter to continue:";
    std::cin.get();
    std::cin.ignore();
    return;
}

/**************************************************************************************************
 ** Function:       removePerson(std::vector<Person>& userLog)
 ** Description:    Removes a visitor who is in the log.
 *************************************************************************************************/
void removePerson(std::vector<Person>& userLog){
    std::string name;
    int roomNumber = 0;

    clearIOStream();                    //clear iostream buffer

    std::cout << "\n\nEnter Name: ";
    std::getline(std::cin, name);

    for ( auto i = userLog.begin() ; i != userLog.end() ; i++ ){    //print userLog Vector
        std::cout << " ";
        if(name.compare(i -> getName(roomNumber))==0){    //match
            userLog.erase(userLog.begin() + std::distance(userLog.begin(),i));
            return;
        }
    }
    std::cout << "Visitor " << name << " is not in the building." << std::endl;
    std::cout << "\n\nPlease hit any key followed by enter to continue:";
    std::cin.get();
    std::cin.ignore();
    return;
}

/**************************************************************************************************
 ** Function:       clearIOStream
 ** Description:    Clears the io stream
 *************************************************************************************************/
void clearIOStream(){
    std::cin.clear();                   //clear stream
    while(std::cin.get()!= '\n'){       //ignores errors before \n escape char
        continue;
    }
}

/**************************************************************************************************
 ** Function:       getValidInput(int &input)
 ** Description:    Catches non-valid entries, cleans up on error and requests new input
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
