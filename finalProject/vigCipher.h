/**************************************************************************************************
 ** Function:       VigenereCipherWheel
 ** Description:    class calc vigenere cipher
 ** Precondition:   none
 ** Postcondition:  none
 *************************************************************************************************/

#ifndef VIGCIPHER_H
#define VIGCIPHER_H

#include <string>
#include <vector>
#include <iostream>
//#include <algorithm>
#include <fstream>
#include <ostream>

namespace Awesome
{
    class VigenereCipherWheel   //-------------------------------------------------------> Req. 24a
    {
    public:
        VigenereCipherWheel(){};    //default constructor   //------------------------> Req. 17, 32
        VigenereCipherWheel(std::string cipherKey){ setKey(cipherKey); };//-----------> Req. 17, 32

        ~VigenereCipherWheel(){ std::cout << "\n\nEnd Program" << std::endl; };

        void setKey(std::string key);
        void getInput(std::string filename);    //puts in storedCipher
        std::string printCipher();              //prints stored cipher to screen
        void printToFile(std::string filename); //prints storedCipher to file
        void encrypt(std::string cipher);           //encrypts cipher
        void encryptFromFile(std::string filename); //encrypts from file, puts in storedCipher
        void decrypt(std::string cipher);           //decrypts cipher
        void decryptFromFile(std::string filename); //decrypts from file, puts in storedCipher

        std::string getKey(){ return key; };


    protected:
        std::string key, storedCipher;
    };

    /**********************************************************************************************
     ** Function:       encryptFromFile
     ** Description:    runs necessary functions to encrypt message from file
    **********************************************************************************************/
    void VigenereCipherWheel::encryptFromFile(std::string filename)
    {
        getInput(filename);
        encrypt(storedCipher);
    }

    /**********************************************************************************************
     ** Function:       decryptFromFile
     ** Description:    runs necessary functions to decrypt message from file
    **********************************************************************************************/
    void VigenereCipherWheel::decryptFromFile(std::string filename)
    {
        getInput(filename);
        decrypt(storedCipher);
    }

    /**********************************************************************************************
     ** Function:       getInput
     ** Description:    pulls text out of file given
    **********************************************************************************************/
    void VigenereCipherWheel::getInput(std::string filename)    //------------------------> Req. 34
    {
        std::ifstream ifs;
        std::string testStr;
        std::vector<std::string> v; //----------------------------------------------------> Req. 31

        ifs.open(filename.c_str());

        while (std::getline(ifs,testStr))   //build vector from file
        {
            v.push_back(testStr);
        }

        for(int i = 0; i < v.size(); i++)   //place vector in storedCipher
        {
            storedCipher += v[i];
        }
    }

    /**********************************************************************************************
     ** Function:       printToFile
     ** Description:    prints cipher to file passed
    **********************************************************************************************/
    void VigenereCipherWheel::printToFile(std::string filename)
    {
        std::ofstream ofs;
        ofs.open(filename.c_str());
        ofs << printCipher();
    }

    /**********************************************************************************************
     ** Function:       printCipher
     ** Description:    Formats and returns cipher as string
    **********************************************************************************************/
    std::string VigenereCipherWheel::printCipher()
    {
        std::string output;
        for(int i = 0 ; i < storedCipher.length() ; i++)
        {
            if(i % 5 == 0 && i != 0)
            {
                if(i % 25 == 0)
                {
                    output += "\n";
                }
                else
                {
                    output += " ";
                }
            }
            output += storedCipher.at(i);
        }
        return output;
    }

    /**********************************************************************************************
     ** Function:       setKey
     ** Description:    makes sure key is setup correctly (all caps) no other chars, nums
    **********************************************************************************************/
    void VigenereCipherWheel::setKey(std::string key)
    {
        for (int i = 0; i < key.length() ; i++)
        {
            if(key[i] >= 'A' && key[i] <= 'Z')
            {
                this->key += key[i];    //case is fine, pass directly to key var.
            }
            else if(key[i] >= 'a' && key[i] <= 'z')
            {
                this->key += key[i] + 'A' - 'a'; //make lower case into upper case//-------> Req. 6
            }
        }
    }

    /**********************************************************************************************
     ** Function:       encrypt
     ** Description:    encrypts message using vig cipher
    **********************************************************************************************/
    void VigenereCipherWheel::encrypt(std::string cipher)
    {
        std::string encrypted;

        for(int i = 0, keyStep = 0 ; i < cipher.length() ; i++) //run through message
        {
            char c = cipher.at(i);  //set current character

            if(c >= 'a' && c <= 'z')
            {
                c += 'A' - 'a'; //make lower case into upper case
            }
            else if(c < 'A' || c > 'Z')
            {
                continue;   //skip if character isnt letter
            }

            encrypted += (c + key[keyStep % key.length()] - 2 * 'A' ) % 26 + 'A'; //encrypt

            keyStep = (keyStep + 1) % key.length();   //next step in the key
        }
        storedCipher = encrypted;
    }


    /**********************************************************************************************
     ** Function:       decrypt
     ** Description:    decrypts message using vig cipher
    **********************************************************************************************/
    void VigenereCipherWheel::decrypt(std::string cipher)
    {
        std::string decrypted;

        for(int i = 0, keyStep = 0 ; i < cipher.length() ; i++) //run through message
        {
            char c = cipher.at(i);  //set current character

            if(c >= 'a' && c <= 'z')
            {
                c += 'A' - 'a'; //make lower case into upper case
            }
            else if(c < 'A' || c > 'Z')
            {
                continue;   //skip if character isnt letter

            }

            decrypted += (c - key[keyStep % key.length()] + 26 ) % 26 + 'A'; //decrypt

            keyStep = (keyStep + 1) % key.length();   //next step in the key
        }
        storedCipher = decrypted;
    }

}   //end class
#endif
