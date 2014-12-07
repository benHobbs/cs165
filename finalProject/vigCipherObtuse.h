#ifndef VIGCIPHEROBTUSE_H
#define VIGCIPHEROBTUSE_H

#include "vigCipher.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace Awesome
{
    class VigenereCipherWheelObtuse : public VigenereCipherWheel    //--------------------> Req. 36
    {
    public:
        VigenereCipherWheelObtuse(std::string key) : VigenereCipherWheel(key)
        {
              /*  intentionally left blank    */
        }

        friend std::ostream& operator<<(std::ostream& output,
                                        const VigenereCipherWheelObtuse& V);//------------> Req. 33
    };

    /**********************************************************************************************
     ** Function:       operator<<
     ** Description:    Overloading of << operator
    **********************************************************************************************/
    std::ostream& operator<<(std::ostream& output, const VigenereCipherWheelObtuse& V)//--> Req. 33
    {
        for(int i = 0 ; i < V.storedCipher.length() ; i++)
        {
            if(i % 5 == 0 && i != 0)
            {
                if(i % 25 == 0)
                {
                    output << "\n";
                }
                else
                {
                    output << " ";
                }
            }
            output << V.storedCipher.at(i);
        }
        return output;
    }
}
#endif
