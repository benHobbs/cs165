/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   3/5/2014
 ** Lab/Project#:   Ex. 15 Problem 1
 ** Filename:       adminEmployee.cpp
 ** Overview: 	    This project creates a new class, administrator employee, which is derived from
 **                 the already existing class salaried employee.
 ** References:     The book for the source code for salaried employee and employee
***************************************************************************************************/
#include <iostream>
#include "employee.h"
#include "salariedemployee.h"
#include "administratoremployee.h"

using namespace SavitchEmployees;

int main()
{
    AdministratorEmployee James("James 'JD' Dean", "Sn. Manager", "Some Insipid Project Manager",
                                 "Sausage Factory", "123-45-6789", 1250.00);

    James.print();

    std::cout << std::endl;

    James.printCheck();

    return 0;
}
