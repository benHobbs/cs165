/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/18/2014
 ** Lab/Project#:   Ex. 12 Problem 1
 ** Filename:       consignmentInventory.cpp
 ** Overview: 	    This is a very basic inventory program for a consignment shop.
 ** Input:  		none
 ** Output: 		none
 ** References:     http://www.dreamincode.net/forums/topic/63358-store-class-objects-in-vector/
***************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>

class Item
{
public:
    Item(); //constructor
    //Accessors
    void getInfo();         //prints out all info on item
    void getMenuListing();  //prints out name, asking price
    //mutators
    void setName(std::string itemName){ name = itemName; }
    void setAge(int itemAge){ age = itemAge; }
    void setColour(std::string itemColour){ colour = itemColour; }
    void setAskingPrice(double itemAskingPrice){ askingPrice = itemAskingPrice; }
    void setPaidPrice(double itemPaidPrice){ paidPrice = itemPaidPrice; }

private:    //private variables
    std::string name;
    int age;
    std::string colour;
    double askingPrice;
    double paidPrice;
};

/**************************************************************************************************
 ** Function:       Item (constructor)
 ** Description:    Intentionally left blank.
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
Item::Item(){ /* Intentionally left blank */}

/**************************************************************************************************
 ** Function:       getMenuList
 ** Description:    Print name and asking price.
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void Item::getMenuListing(){
    std::cout << name << ", $" << askingPrice << std::endl;
}

/**************************************************************************************************
 ** Function:       getInfo
 ** Description:    Prints all info for object
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void Item::getInfo(){
    std::cout << "  Name:\t\t" << name << std::endl;
    std::cout << "  Asking Price:\t$" << askingPrice << std::endl;
    std::cout << "  Price Paid:\t$" << paidPrice << std::endl;
    std::cout << "  Age:\t\t" << age << " age units" << std::endl;
    std::cout << "  Colour:\t" << colour << std::endl << std::endl;
}


/**************************************************************************************************
 ** Main ******************************************************************************************
 *************************************************************************************************/

void printMenu(std::vector<Item>& inventory);
void newItem(std::vector<Item>& inventory);
void clearIOStream();                   //clear iostream buffer
void printDetailedList(std::vector<Item>& inventory);
void getValidInput(double &input);      //double version
void getValidInput(int &input);         //int version
void getValidInput(std::string &input); //string version

int main()
{
    //declare variables
    std::vector<Item> inventory;
    char userInput;

    do{
        printMenu(inventory);   //print the menu
        std::cin >> userInput;  //get option from user
        switch(userInput){      //options
        case 'a':{                  //add new item
            newItem(inventory);
            break;}
        case 'p':{                  //print detailed list
            printDetailedList(inventory);
            break;}
        case 'e':
            return 0;
        default:
            std::cout << "Invalid\n\n\n";
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
void printMenu(std::vector<Item>& inventory){
    std::cout << " ----------Inventory----------\n\n";
    for ( auto i = inventory.begin() ; i != inventory.end() ; i++ ){
        std::cout << " ";
        i -> getMenuListing();
    }
    std::cout << "\n\n[a]dd new item; [p]rint detailed list; [e]xit program: ";
}

/**************************************************************************************************
 ** Function:       printMenu
 ** Description:    Prints Inventory System Menu
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
void newItem(std::vector<Item>& inventory){

    std::string name, colour = "n/a";
    int age = 0;
    double askingPrice = 0.0, paidPrice = 0.0;

    clearIOStream();

    Item *item1;

    std::cout << std::endl << std::endl;
    std::cout << " ----------Add New Item----------\n\n";
    std::cout << " Enter Name: ";
    std::getline(std::cin, name);

    std::cout << " Enter Asking Price: ";
    getValidInput(askingPrice);

    char userInput;
    do{
        std::cout << " Input Optional Attributes (y/n): ";
        std::cin >> userInput;
    } while (userInput != 'y' && userInput != 'n' );
    if ( userInput == 'y' ){
        std::cout << "\n Age: ";
        getValidInput(age);
        std::cout << " Colour: ";
        getValidInput(colour);
        std::cout << " Price Paid: ";
        getValidInput(paidPrice);
    }
    std::cout << std::endl << std::endl;

    item1 = new Item;
    item1 -> setName(name);
    item1 -> setAge(age);
    item1 -> setColour(colour);
    item1 -> setAskingPrice(askingPrice);
    item1 -> setPaidPrice(paidPrice);

    inventory.push_back(*item1);

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
 ** Function:       printDetailedList
 ** Description:    Prints all details for full inventory
 ** Input:          std::vector<Item>& inventory || vector of items (objects)
 ** Output:         none
 *************************************************************************************************/
void printDetailedList(std::vector<Item>& inventory){
    std::cout << std::endl << std::endl;
    std::cout << " ----------Detailed List----------\n\n";
    for ( auto i = inventory.begin() ; i != inventory.end() ; i++ ){
        i -> getInfo();
    }
    std::cout << std::endl << std::endl;
}


/**************************************************************************************************
 ** Function:       getValidInput
 ** Description:    Catches non-valid entries, cleans up on error and requests new input
 ** Input:          std::string &input || input (by ref) to test
 ** Output:         none
 *************************************************************************************************/
void getValidInput(std::string &input){
    while(!(std::cin >> input)){    //catches non valid entries
        std::cin.clear();           //clear stream
        while(std::cin.get()!= '\n'){    //ignores errors before \n escape char
            continue;
        }
        std::cout << "\tPlease enter a valid input: ";
    }
}

/**************************************************************************************************
 ** Function:       getValidInput
 ** Description:    Catches non-valid entries, cleans up on error and requests new input
 ** Input:          double &input || input (by ref) to test
 ** Output:         none
 *************************************************************************************************/
void getValidInput(double &input){
    while(!(std::cin >> input)){    //catches non valid entries
        std::cin.clear();           //clear stream
        while(std::cin.get()!= '\n'){    //ignores errors before \n escape char
            continue;
        }
        std::cout << "\tPlease enter a valid input: ";
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
