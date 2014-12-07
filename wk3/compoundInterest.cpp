/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/13/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Excercise 5, problem 6
** 	Filename: compoundInterest.cpp
**
** 	Overview: 	Calculates compound interest.
**
** 	Input:		Initial Deposit
**              Interest Rate
**              Years till maturity
**
** 	Output:		Final amount in fund
**
**  References: http://www.cplusplus.com/reference/cmath/pow/ power 'operator'
**
***************************************************************************************************/
#include <iostream>	//std::cout, std::cin
#include <math.h>   //power

void compoundInterest(float &finalAmount, float &initDep, float &interestRate, int years);

int main()
{
    float initialDeposit = 0.0, interestRate = 0.0, finalAmount, finalAmount1;
    int years;

    std::cout << "This program will calculate compound interest.\nPlease enter your initial "
              << "deposit amount: $";
    std::cin >> initialDeposit;
    std::cout << "\nPlease enter the interest rate: ";
    std::cin >> interestRate;
    std::cout << "\nHow many years will the money be in this investment? ";
    std::cin >> years;

    finalAmount1 =  initialDeposit * pow( ( 1 + ( interestRate / 100 ) ), years);   //test against
    compoundInterest(finalAmount, initialDeposit, interestRate, years); //calls recursive func.

    std::cout << "Your final total is: $" << finalAmount << std::endl;
//    std::cout << "Your final total is: $" << finalAmount1 << std::endl;

    return 0;
}

void compoundInterest(float &finalAmount, float &initDep, float &interestRate, int years)
{
    if ( years < 2 )
    {
        finalAmount = initDep + ( initDep * ( interestRate / 100 ) );
    }
    else
    {
        initDep = initDep + ( initDep * ( interestRate / 100 ) );
        compoundInterest(finalAmount,initDep,interestRate,years-1);
    }
}
