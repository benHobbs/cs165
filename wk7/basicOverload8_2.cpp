/**************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/18/2014
 ** Lab/Project#:   Ex. 13 Problem 1
 ** Filename:       basicOverload8_2.cpp
 ** Overview: 	    Build and test class Rational (which is essentially a class to deal with
 **                 rational numbers).
 ** References:     http://www.cplusplus.com/reference/string/string/c_str/
 **                 http://www.cplusplus.com/forum/general/13135/
 **                 http://www.mathsisfun.com/simplifying-fractions.html
 **                 http://en.wikipedia.org/wiki/Euclidean_algorithm#Description    gcd function
 ** Notes:          Please note that usually mathematical functions would be called as such:
 **                     v3 = v1 + v2;
 **                 However, the tests below simply print the values without forcing normalization.
 **                 Ergo, some of the printouts might not be normalized, however, the class itself
 **                 always normalizes Rationals on any method of entry.  To see an example where
 **                 a third Rational is set equal to the sum of two others (and then normalized b/c
 **                 the values where stored in a 3rd rational) please see testAssignmentOperator();
**************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>


class Rational
{
public:
    //constructors
    Rational(){ numerator = 0, denominator = 1; }   //default constructor
    Rational(int wholeNumber){ numerator = wholeNumber, denominator = 1; }//whole num constr.
    Rational(int iNumerator, int iDenominator){     //rational number constructor, normalizer
        normalizeSign(iNumerator, iDenominator);
        noramalizeReduce(iNumerator, iDenominator);
    }

    void normalizeSign(int &iNumerator, int &iDenominator);     //set sign
    void noramalizeReduce(int iNumerator, int iDenominator);    //reduce fraction, assign

    void normalize();

    void printNumber();

    int getNumerator(){ return numerator; }
    int getDenominator(){ return denominator; }

    void setNumerator(int iNumerator){ numerator = iNumerator; }
    void setDenominator(int iDenominator){ denominator = iDenominator; }

    int gcd(int a, int b);

    friend std::ostream& operator<<(std::ostream& output, const Rational& R);
    friend std::istream& operator>>(std::istream& input, const Rational& R);

private:
    int numerator;      //the top of the fraction
    int denominator;    //the bottom of the fraction
};



void Rational::normalize(){
    int iNumerator = getNumerator(), iDenominator = getDenominator();

    normalizeSign(iNumerator, iDenominator);
    noramalizeReduce(iNumerator,iDenominator);

    if (getDenominator() < 1){  //non-valid rational # (x/0)
        std::cout << "This number is not a valid rational number.  Please enter x/y, where"
                  << " y != 0:" << std::endl;
        setNumerator(0), setDenominator(1);
    }
}


/**************************************************************************************************
 ** Function:       normalizeSign
 ** Description:    Returns (by ref), the numerator and denominator in the correct format (-)x/y.
 *************************************************************************************************/
void Rational::normalizeSign(int &iNumerator, int &iDenominator){
    if (iNumerator < 0 && iDenominator < 0){    //both are negative
        numerator = abs(iNumerator), denominator = abs(iDenominator);   //make positive
    }
    else if (iDenominator < 0){ //denominator is negative, numerator is positive
        iNumerator = (iNumerator* (-1)), iDenominator = (iDenominator * (-1));
    }
}

/**************************************************************************************************
 ** Function:       normalizeReduce
 ** Description:    Reduces and assigns the numerator and denominator.
 *************************************************************************************************/
void Rational::noramalizeReduce(int iNumerator, int iDenominator){
    numerator = iNumerator / gcd(iNumerator, iDenominator);
    denominator = iDenominator / gcd(iNumerator, iDenominator);
}

/**************************************************************************************************
 ** Function:       gcd
 ** Description:    Given the numerator and denominator, returns greatest common denominator.
 *************************************************************************************************/
int Rational::gcd(int iNumerator, int iDenominator){
    if (iDenominator == 0){
        return iNumerator;
    }
    return gcd(iDenominator, iNumerator % iDenominator);
}

/**************************************************************************************************
 ** Function:       operator <<
 ** Description:    Assign a Rational to the ostream.
 ** Input:          std::ostream& output    || ostream
 **                 const Rational& R       || Rational Number
 ** Output:         std::ostream&           || Rational Number as output
 *************************************************************************************************/
std::ostream& operator<<(std::ostream& output, const Rational& R){
    output << R.numerator << '/' << R.denominator;
    return output;
}

/**************************************************************************************************
 ** Function:       operator >>
 ** Description:    Gets input from the istream, places it into Rational object.
 ** Input:          none
 ** Output:         none
 *************************************************************************************************/
std::istream& operator>>(std::istream& input, Rational& R){
    std::string userInput, sNumerator, sDenominator;
    int slash = 0, iNumerator, iDenominator;

    input >> userInput;

    slash = userInput.find_first_of("/");

    if (slash != -1){       //correct format
        sNumerator = userInput.substr(0,slash);
        sDenominator = userInput.substr(slash+1, userInput.length());

        iNumerator = atoi(sNumerator.c_str());
        iDenominator = atoi(sDenominator.c_str());

        R.setNumerator(iNumerator), R.setDenominator(iDenominator);
        R.normalize();
    }
    else{
        std::cout << "This number is not in the correct format.  Please enter x/y:" << std::endl;
    }

    return input;
}

/**************************************************************************************************
 ** Function:       operator +
 ** Description:    Add R1 to R2.
 ** Input:          Rational& R1    || First Rational Number
 **                 Rational& R2    || First Rational Number
 ** Output:         Rational        || Returned Rational Number (answer)
 *************************************************************************************************/
Rational operator +(Rational& R1, Rational& R2){
    int finalNumerator = 0, finalDenominator = 0;

    if (R1.getDenominator() == R2.getDenominator()){    //same denominator, simple addition
        finalNumerator = R1.getNumerator() + R2.getNumerator();
        finalDenominator = R1.getDenominator();
    }
    else{                                               //not the same denominator, vicious maths
        finalNumerator = (R1.getNumerator() * R2.getDenominator())
                                + (R2.getNumerator() * R1.getDenominator());
        finalDenominator = R1.getDenominator() * R2.getDenominator();
    }

    return Rational(finalNumerator, finalDenominator);
}

/**************************************************************************************************
 ** Function:       operator -
 ** Description:    Subtracts R2 from R1.
 ** Input:          Rational& R1    || First Rational Number
 **                 Rational& R2    || First Rational Number
 ** Output:         Rational        || Returned Rational Number (answer)
 *************************************************************************************************/
Rational operator -(Rational& R1, Rational& R2){
    int finalNumerator = 0, finalDenominator = 0;

    if (R1.getDenominator() == R2.getDenominator()){    //same denominator, simple addition
        finalNumerator = R1.getNumerator() - R2.getNumerator();
        finalDenominator = R1.getDenominator();
    }
    else{                                               //not the same denominator, vicious maths
        finalNumerator = (R1.getNumerator() * R2.getDenominator())
                                - (R2.getNumerator() * R1.getDenominator());
        finalDenominator = R1.getDenominator() * R2.getDenominator();
    }

    return Rational(finalNumerator, finalDenominator);
}

/**************************************************************************************************
 ** Function:       operator *
 ** Description:    Multiplies two Rational objects.
 ** Input:          Rational& R1    || First Rational Number
 **                 Rational& R2    || First Rational Number
 ** Output:         Rational        || Returned Rational Number (answer)
 *************************************************************************************************/
Rational operator *(Rational& R1, Rational& R2){
    int finalNumerator = 0, finalDenominator = 0;

    finalNumerator = R1.getNumerator() * R2.getNumerator();
    finalDenominator = R1.getDenominator() * R2.getDenominator();

    return Rational(finalNumerator, finalDenominator);
}

/**************************************************************************************************
 ** Function:       operator /
 ** Description:    Divides two Rational objects.
 ** Input:          Rational& R1    || First Rational Number
 **                 Rational& R2    || First Rational Number
 ** Output:         Rational        || Returned Rational Number (answer)
 *************************************************************************************************/
Rational operator /(Rational& R1, Rational& R2){
    int finalNumerator = 0, finalDenominator = 0;
    Rational reciprocal(R2.getDenominator(), R2.getNumerator());

    finalNumerator = R1.getNumerator() * reciprocal.getNumerator();
    finalDenominator = R1.getDenominator() * reciprocal.getDenominator();

    return Rational(finalNumerator, finalDenominator);
}

/**************************************************************************************************
 ** Function:       operator ==
 ** Description:    Compares two Rational objects.
 ** Input:          Rational& R1    || First Rational Number
 **                 Rational& R2    || First Rational Number
 ** Output:         bool            || answer
 *************************************************************************************************/
bool operator ==(Rational& R1, Rational& R2){
    return ((R1.getNumerator() == R2.getNumerator())
            && (R1.getDenominator() == R2.getDenominator()));
}

/**************************************************************************************************
 ** Function:       operator !=
 ** Description:    Compares two Rational objects.
 ** Input:          Rational& R1    || First Rational Number
 **                 Rational& R2    || First Rational Number
 ** Output:         bool            || answer
 *************************************************************************************************/
bool operator !=(Rational& R1, Rational& R2){
    return !((R1.getNumerator() == R2.getNumerator())
            && (R1.getDenominator() == R2.getDenominator()));
}

/**************************************************************************************************
 ** Function:       operator <
 ** Description:    Compares two Rational objects.
 ** Input:          Rational& R1    || First Rational Number
 **                 Rational& R2    || First Rational Number
 ** Output:         bool            || answer
 *************************************************************************************************/
bool operator <(Rational& R1, Rational& R2){
    double dR1 = R1.getNumerator() / R1.getDenominator();
    double dR2 = R2.getNumerator() / R2.getDenominator();

    return dR1 < dR2;
}

/**************************************************************************************************
 ** Function:       operator >
 ** Description:    Compares two Rational objects.
 ** Input:          Rational& R1    || First Rational Number
 **                 Rational& R2    || First Rational Number
 ** Output:         bool            || answer
 *************************************************************************************************/
bool operator >(Rational& R1, Rational& R2){
    double dR1 = R1.getNumerator() / R1.getDenominator();
    double dR2 = R2.getNumerator() / R2.getDenominator();

    return dR1 > dR2;
}

/**************************************************************************************************
 ** Function:       operator <=
 ** Description:    Compares two Rational objects.
 ** Input:          Rational& R1    || First Rational Number
 **                 Rational& R2    || First Rational Number
 ** Output:         bool            || answer
 *************************************************************************************************/
bool operator <=(Rational& R1, Rational& R2){
    double dR1 = R1.getNumerator() / R1.getDenominator();
    double dR2 = R2.getNumerator() / R2.getDenominator();

    return dR1 <= dR2;
}

/**************************************************************************************************
 ** Function:       operator >=
 ** Description:    Compares two Rational objects.
 ** Input:          Rational& R1    || First Rational Number
 **                 Rational& R2    || First Rational Number
 ** Output:         bool            || answer
 *************************************************************************************************/
bool operator >=(Rational& R1, Rational& R2){
    double dR1 = R1.getNumerator() / R1.getDenominator();
    double dR2 = R2.getNumerator() / R2.getDenominator();

    return dR1 >= dR2;
}

/**************************************************************************************************
 ** Main ******************************************************************************************
 *************************************************************************************************/

void testAssignmentOperator();
void testRAssignmentOperator();
void testPlusOperator();
void testMinusOperator();
void testMultiplicationOperator();
void testDivisionOperator();
void testCompareOperator();
void testNotEqualOperator();
void testLSmallerOperator();
void testRSmallerOperator();
void testLSmallerOrEqualOperator();
void testRSmallerOrEqualOperator();

int main()
{
    testAssignmentOperator();
    testRAssignmentOperator();
    testPlusOperator();
    testMinusOperator();
    testMultiplicationOperator();
    testDivisionOperator();
    testCompareOperator();
    testNotEqualOperator();
    testLSmallerOperator();
    testRSmallerOperator();
    testLSmallerOrEqualOperator();
    testRSmallerOrEqualOperator();

    return 0;
}

void testAssignmentOperator(){
    Rational aNum(5,2), bNum(4,8);
    Rational cNum(6), dNum(-5,-3);
    Rational eNum, fNum(-9);
    Rational gNum;

    gNum = aNum + bNum;

    std::cout << "Test Assignment Operator:\n";
    std::cout << gNum << std::endl;
    std::cout << aNum << ":" << bNum << std::endl;
    std::cout << cNum << ":" << dNum << std::endl;
    std::cout << eNum << ":" << fNum << std::endl;
    std::cout << aNum << "+" << bNum << "=" << gNum << std::endl;
}

void testRAssignmentOperator(){
    Rational aNum;
    std::cout << "Test >> Assignment Operator:\n";
    std::cout << aNum << std::endl;
    std::cin >> aNum;
    std::cout << aNum << std::endl;
}

void testPlusOperator(){
    Rational aNum(1,2), bNum(1,2);
    Rational cNum(6), dNum(-5,3);
    Rational eNum, fNum(-9);

    std::cout << "Test Addition Operator:\n";
    std::cout << aNum << "+" << bNum << "=" << aNum + bNum << std::endl;
    std::cout << cNum << "+" << dNum << "=" << cNum + dNum << std::endl;
    std::cout << eNum << "+" << fNum << "=" << eNum + fNum << std::endl << std::endl;
}

void testMinusOperator(){
    Rational aNum(1,2), bNum(1,2);
    Rational cNum(6), dNum(-5,3);
    Rational eNum, fNum(-9);

    std::cout << "Test Minus Operator:\n";
    std::cout << aNum << "-" << bNum << "=" << aNum - bNum << std::endl;
    std::cout << cNum << "-" << dNum << "=" << cNum - dNum << std::endl;
    std::cout << eNum << "-" << fNum << "=" << eNum - fNum << std::endl << std::endl;
}

void testMultiplicationOperator(){
    Rational aNum(1,2), bNum(1,2);
    Rational cNum(6), dNum(-5,3);
    Rational eNum, fNum(-9);

    std::cout << "Test Multiplication Operator:\n";
    std::cout << aNum << "*" << bNum << "=" << aNum * bNum << std::endl;
    std::cout << cNum << "*" << dNum << "=" << cNum * dNum << std::endl;
    std::cout << eNum << "*" << fNum << "=" << eNum * fNum << std::endl << std::endl;
}

void testDivisionOperator(){
    Rational aNum(1,2), bNum(1,2);
    Rational cNum(6), dNum(5,3);
    Rational eNum, fNum(-9);

    std::cout << "Test Division Operator:\n";
    std::cout << aNum << "/" << bNum << "=" << aNum / bNum << std::endl;
    std::cout << cNum << "/" << dNum << "=" << cNum / dNum << std::endl;
    std::cout << eNum << "/" << fNum << "=" << eNum / fNum << std::endl << std::endl;
}

void testCompareOperator(){
    Rational aNum(1,2), bNum(1,2);
    Rational cNum(6), dNum(-5,3);
    Rational eNum, fNum(-9);

    std::cout << "Test Compare Operator:\n";
    std::cout << aNum << "==" << bNum << "=" << (aNum == bNum) << std::endl;
    std::cout << cNum << "==" << dNum << "=" << (cNum == dNum) << std::endl;
    std::cout << eNum << "==" << fNum << "=" << (eNum == fNum) << std::endl << std::endl;
}

void testNotEqualOperator(){
    Rational aNum(1,2), bNum(1,2);
    Rational cNum(6), dNum(-5,3);
    Rational eNum, fNum(-9);

    std::cout << "Test Not Equal Operator:\n";
    std::cout << aNum << "!=" << bNum << "=" << (aNum != bNum) << std::endl;
    std::cout << cNum << "!=" << dNum << "=" << (cNum != dNum) << std::endl;
    std::cout << eNum << "!=" << fNum << "=" << (eNum != fNum) << std::endl << std::endl;
}

void testLSmallerOperator(){
    Rational aNum(1,2), bNum(1,2);
    Rational cNum(6), dNum(-5,3);
    Rational eNum, fNum(-9);

    std::cout << "Test < Operator:\n";
    std::cout << aNum << "<" << bNum << "=" << (aNum < bNum) << std::endl;
    std::cout << cNum << "<" << dNum << "=" << (cNum < dNum) << std::endl;
    std::cout << eNum << "<" << fNum << "=" << (eNum < fNum) << std::endl << std::endl;
}

void testRSmallerOperator(){
    Rational aNum(1,2), bNum(1,2);
    Rational cNum(6), dNum(-5,3);
    Rational eNum, fNum(-9);

    std::cout << "Test > Operator:\n";
    std::cout << aNum << ">" << bNum << "=" << (aNum > bNum) << std::endl;
    std::cout << cNum << ">" << dNum << "=" << (cNum > dNum) << std::endl;
    std::cout << eNum << ">" << fNum << "=" << (eNum > fNum) << std::endl << std::endl;
}

void testLSmallerOrEqualOperator(){
    Rational aNum(1,2), bNum(1,2);
    Rational cNum(6), dNum(-5,3);
    Rational eNum, fNum(-9);

    std::cout << "Test <= Operator:\n";
    std::cout << aNum << "<=" << bNum << "=" << (aNum <= bNum) << std::endl;
    std::cout << cNum << "<=" << dNum << "=" << (cNum <= dNum) << std::endl;
    std::cout << eNum << "<=" << fNum << "=" << (eNum <= fNum) << std::endl << std::endl;
}

void testRSmallerOrEqualOperator(){
    Rational aNum(1,2), bNum(1,2);
    Rational cNum(6), dNum(-5,3);
    Rational eNum, fNum(-9);

    std::cout << "Test >= Operator:\n";
    std::cout << aNum << ">=" << bNum << "=" << (aNum >= bNum) << std::endl;
    std::cout << cNum << ">=" << dNum << "=" << (cNum >= dNum) << std::endl;
    std::cout << eNum << ">=" << fNum << "=" << (eNum >= fNum) << std::endl << std::endl;
}
