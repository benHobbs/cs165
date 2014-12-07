/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/18/2014
 ** Lab/Project#:   Ex. 13 Problem 1
 ** Filename:       basicOverload8_2.cpp
 ** Overview: 	    Class holds x and y coords
 ** Input:  		none
 ** Output: 		none
 ** References:     http://www.cplusplus.com/reference/string/string/c_str/
 **                 http://www.cplusplus.com/forum/general/13135/
***************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>


class Vector2D
{
public:
    Vector2D(int x, int y){ x_value = x, y_value = y; }
    void setVectorXY(int x, int y);
    int getX(){ return x_value; }
    int getY(){ return y_value; }

    friend std::ostream& operator<<(std::ostream& output, const Vector2D& v);

private:
    int x_value;
    int y_value;
};

/**************************************************************************************************
 ** Function:       operator <<
 ** Description:    Assign a Rational to the ostream.
 ** Input:          std::ostream& output    || ostream
 **                 Vector2D v              || Vector2D to be sent to ostream
 ** Output:         std::ostream&           || Vector2D as output
 *************************************************************************************************/
std::ostream& operator<<(std::ostream& output, Vector2D& v){
    output << "(" << v.getX() << "," << v.getY() << ")";
    return output;
}


/**************************************************************************************************
 ** Function:       operator *
 ** Description:    Multiplies two Vector2D objects.
 ** Input:          Vector2D v1    || First Vector2D
 **                 Vector2D v2    || First Vector2D
 ** Output:         Vector2D       || Returned Vector2D (answer)
 *************************************************************************************************/
Vector2D operator *(Vector2D v1, Vector2D v2){
    return Vector2D(v1.getX() * v2.getX(),v2.getY() * v2.getY());
}


/**************************************************************************************************
 ** Main ******************************************************************************************
 *************************************************************************************************/

int main()
{
    Vector2D v1(3,2), v2(8,2), v3(0,0);

    v3 = v1 * v2;

    std::cout << v1 << "*" << v2 << "=" << v3 << std::endl;

    return 0;
}
