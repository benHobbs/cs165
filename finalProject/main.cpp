/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   3/16/2014
 ** Lab/Project#:   Final Project
 ** Filename:       finalProject.cpp
 ** Overview:       This program uses the class VigenereCipherWheel to encrypt of decrypt missives.
 **                 Instructions are provided when the program is run without any command line
 **                 arguments.
***************************************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>   //--------------------------------------------------------------------> Req. 35
#include <vector>

#include "vigCipher.h"
#include "vigCipherObtuse.h"

#define rundate __DATE__    //-------------------------------------------------------------> Req. 3
#define runtime __TIME__    //-------------------------------------------------------------> Req. 3

using namespace Awesome;    //--------------------------------------------------------> Req. 28, 39

void getValidInput(char &input);    //----------------------------------------------------> Req. 13
void getValidInput(std::string &input);
void basicProgram();
int parseCommandArguments(int argc, char* argv[],
                            std::string &filename1, std::string &filename2);//----> Req. 16, 28, 39

struct table    //---------------------------------------------------------------------> Req. 23,15
{
    std::string alphabet;	 //-------------------------------------------------------> Req. 18
    char arr[26][26];   //----------------------------------------------------------------> Req. 20
    int x;
};

void vigenereCipherTable();
void vigenereCipherTablePrint(int i, table *p); //----------------------------------------> Req. 16
template <typename T>   //----------------------------------------------------------------> Req. 37
void printValue(T a){ std::cout << a; }


int main(int argc, char* argv[])
{
    if(argc == 1)   //no command args, run basic program--------------------------------> Req. 7, 8
    {
        std::cout << "Vigenere Cipher Program (last compiled on " << rundate << " at " << runtime
                  << ")\n\nThis program uses a key and a message to encrypt or decrypt said\n"
                  << "message using the vigenere cipher.  For more information please\n"
                  << "visit http://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher.\n\n";//-----> Req. 4
        std::cout << "To use this program:\n"
            << "./vigCyph [b]..............................| Run the basic program\n"
            << "./vigCyph [e] [filename]...................| Encrypt the given file to screen\n"
            << "./vigCyph [d] [filename]...................| Decrypt the given file to screen\n"
            << "./vigCyph [e] [filename] [filename]........| Encrypt first file to second\n"
            << "./vigCyph [d] [filename] [filename]........| Decrypt first file to second\n\n"
            << "./vigCyph [t]..............................| Prints Vinegere Cipher table\n\n"
            << "If the second file does not exist, the program will create the file.\n\n";
    }
    else
    {
        std::string filename1, filename2, key;

        switch(parseCommandArguments(argc, argv, filename1, filename2)) //------------> Req. 14, 22
        {
            case 1: //run the basic program
            {
                basicProgram();
                break;
            }
            case 2: //encrypt to screen
            {
                std::cout << "Vigenere Cipher Program : encrypt to screen\n";
                std::cout << "Please enter your key: ";
                getValidInput(key); //-----------------------------------------------------> Req. 5
                VigenereCipherWheel cipher(key);    //-----------------------------------> Req. 24b
                cipher.encryptFromFile(filename1);
                std::cout << cipher.printCipher();
                break;
            }
            case 3: //encrypt to file
            {
                std::cout << "Vigenere Cipher Program : encrypt to file\n";
                std::cout << "Please enter your key: ";
                getValidInput(key);

                VigenereCipherWheel *pCipher;
                pCipher = new VigenereCipherWheel(key); //--------------------------------> Req. 27
                pCipher->encryptFromFile(filename1);
                pCipher->printToFile(filename2);

                std::cout << "\nencrypted to file: success\n";
                break;
            }
            case 4: //decrypt to screen
            {
                std::cout << "Vigenere Cipher Program : decrypt to screen\n";
                std::cout << "Please enter your key: ";

                getValidInput(key);
                VigenereCipherWheel cipher(key);
		//hold
                cipher.decryptFromFile(filename1);
                std::cout << cipher.printCipher();
                break;
            }
            case 5:
            {
                std::cout << "Vigenere Cipher Program : decrypt to file\n";
                std::cout << "Please enter your key: ";
                getValidInput(key);
                VigenereCipherWheel cipher(key);
                cipher.decryptFromFile(filename1);
                cipher.printToFile(filename2);
                break;
            }
            case 6:
            {
                vigenereCipherTable();
                break;
            }
            default:
            {
                std::cout << "Program does not recognize this command. "
                          << "Please verify and re-run." << std::endl;
                break;
            }
        }
    }
}

/**************************************************************************************************
 ** Function:       parseCommandArguments
 ** Description:    determines how program will run
**************************************************************************************************/
int parseCommandArguments(int argc, char* argv[], std::string &filename1, std::string &filename2)
{
    std::string *args = new std::string[argc];   //-----------------------------------> Req. 21, 25

    int returnValue = 0;

    for(int i = 0 ; i < argc ; i++ )    //-------------------------------------------------> Req. 9
    {
         args[i] = argv[i];
    }

    if(args[1] == "b")      //run basic program
    {
        returnValue = 1;
    }
    else if(args[1] == "t")      //print table
    {
        returnValue = 6;
    }
    else if(args[1] == "e") //encrypt source
    {
        if(argc == 3)       //to screen
        {
            filename1 = args[2];
            returnValue = 2;
        }
        else if(argc == 4)  //to file
        {
            filename1 = args[2];
            filename2 = args[3];
            returnValue = 3;
        }
        else                //incorrect usage
        {
            returnValue = -1;
        }
    }
    else if(args[1] == "d")
    {
        if(argc == 3)       //to screen
        {
            filename1 = args[2];
            returnValue = 4;
        }
        else if(argc == 4)  //to file
        {
            filename1 = args[2];
            filename2 = args[3];
            returnValue = 5;
        }
        else                //incorrect usage
        {
            returnValue = -1;
        }
    }
    else
    {
        returnValue = -1;
    }

    delete []args;  //clear memory from dynamically allocated array

    return returnValue;
}

/**************************************************************************************************
 ** Function:       basicProgram
 ** Description:    runs the very basic vig cipher program, allows user to encrypt/decrypt
**************************************************************************************************/
void basicProgram()
{
        std::string key, msg, type;

        std::cout << "Vigenere Cipher (Basic)\nPlease enter your key: ";
        std::getline(std::cin,key);

        std::cout << "Please enter your message: ";
        std::getline(std::cin, msg);

        char input;
        do
        {
            std::cout << "(e)ncrypt/(d)ecrypt: ";
            getValidInput(input);
        } while (input != 'd' && input != 'e');

        VigenereCipherWheel cipher(key);

        if(input == 'e')
        {
            type = "encrypted message reads:\n\n";
            cipher.encrypt(msg);
        }
        else
        {
            type = "decrypted message reads:\n\n";
            cipher.decrypt(msg);
        }

        std::cout << type << cipher.printCipher() << " STOP\n";
}


/**************************************************************************************************
 ** Function:       getValidInput
 ** Description:    Catches non-valid entries, cleans up on error and requests new input
 ** Input:          char &input || input (by ref) to test
**************************************************************************************************/
void getValidInput(char &input)
{
    while(!(std::cin >> input)) //catches non valid entries
    {
        std::cin.clear();       //clear stream
        while(std::cin.get()!= '\n')    //ignores errors before \n escape char
        {
            continue;
        }
        std::cout << "\tPlease enter a valid input: ";
    }
}

/**************************************************************************************************
 ** Function:       getValidInput
 ** Description:    Catches non-valid entries, cleans up on error and requests new input
 ** Input:          std::string &input || input (by ref) to test
**************************************************************************************************/
void getValidInput(std::string &input)
{
    while(!(std::getline(std::cin, input))) //catches non valid entries
    {
        std::cin.clear();       //clear stream
        while(std::cin.get()!= '\n')    //ignores errors before \n escape char
        {
            continue;
        }
        std::cout << "\tPlease enter a valid input: ";
    }
}

/**************************************************************************************************
 ** Function:       vigenereCipherTable()
 ** Description:    Creates a vigenere table for giggles
**************************************************************************************************/
void vigenereCipherTable()
{
    table *p;   //------------------------------------------------------------------------> Req. 26
    p = new table;
    p->x = 26;
    p->alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0 ; i <= p->alphabet.length() - 1; i++)
    {
        for (int j = 0 ; j <= p->alphabet.length() - 1 ; j++)
        {
            p->arr[i][j] = p->alphabet.at((i+j) % 26);
        }
    }

    try     //----------------------------------------------------------------------------->req. 38
    {
        //throw 0;  //use to test try catch //----------------------------------------> Req. 11, 12
        std::cout << "A Sample Vigenere Table\n\n";
        vigenereCipherTablePrint(0, p);
        std::cout << "\n\nEnd Program" << std::endl;
    }
    catch(...)
    {
        srand(time(NULL));      //init rand generator
        std::cout << "The incredibly arduous print method suffered a failure.  Lets face it\n"
                  << "nobody is surprised here.  As a consolation, here is a random number\n";
        printValue(rand() % 1000 + 1);  //--------------------------------------------> Req. 10, 37
        std::cout << "." << std::endl;
    }
}

/**************************************************************************************************
 ** Function:       vigenereCipherTablePrint()
 ** Description:    Prints out a vinegere table for use in encryption
**************************************************************************************************/
void vigenereCipherTablePrint(int i, table *p)      //--------------------------------> Req. 19, 40
{
    if (i == 0)
    {
        std::cout << " " << p->alphabet << std::endl;
    }
    if (i < p->x)
    {
        std::cout << p->alphabet.at(i);
        for (int j = 0 ; j < p->x ; j++)
        {
            std::cout << p->arr[i][j];
        }
        std::cout << std::endl;
        vigenereCipherTablePrint(i = i + 1, p);
    }
}

