//This is the file salariedemployee.cpp
//This is the implementation for the class SalariedEmployee.
//The interface for the class SalariedEmployee is in
//the header file salariedemployee.h.
#include <iostream>
#include <string>
#include "administratoremployee.h"

namespace SavitchEmployees
{

    AdministratorEmployee::AdministratorEmployee( ) : SalariedEmployee( )
    {
        //deliberately empty
    }

    AdministratorEmployee::AdministratorEmployee (std::string theName, std::string theTitle,
                               std::string theSupervisor, std::string aor, std::string theSsn,
                               double theWeeklySalary)
                     : SalariedEmployee(theName, theSsn, theWeeklySalary),
                       adminTitle(theTitle), immediateSupervisor(theSupervisor),
                       areaOfResponsibility(aor)
    {
        //deliberately empty
    }

    void AdministratorEmployee::setSupervisor(std::string newSupervisor)
    {
        immediateSupervisor = newSupervisor;
    }

    void AdministratorEmployee::setTitle(std::string newTitle)
    {
        adminTitle = newTitle;
    }

    std::string AdministratorEmployee::getTitle()
    {
        return adminTitle;
    }

    void AdministratorEmployee::setImmediateSupervisor(std::string newSupervisor)
    {
        immediateSupervisor = newSupervisor;
    }

    std::string AdministratorEmployee::getSupervisor()
    {
        return immediateSupervisor;
    }

    void AdministratorEmployee::setAreaOfResponsibility(std::string newAOR)
    {
        areaOfResponsibility = newAOR;
    }

    std::string AdministratorEmployee::getAOR()
    {
        return areaOfResponsibility;
    }

    void AdministratorEmployee::print(){
        std::cout << "Administrator Employee Information\n\nName: " << Employee::getName() << ", "
                  << getTitle() << ", " << getAOR() << "\n\nImmediate Supervisor: "
                  << getSupervisor() << "\n\nEmployee SSN: " << Employee::getSsn() << std::endl;
    }

    void AdministratorEmployee::printCheck( ){
        setNetPay(salary);
        std::cout << "\n__________________________________________________\n";
        std::cout << "Pay to the order of " << getName( ) << std::endl;
        std::cout << "The sum of " << getNetPay( ) << " Dollars\n";
        std::cout << "_________________________________________________\n";
        std::cout << "Check Stub NOT NEGOTIABLE \n";
        std::cout << "Employee Number: " << getSsn( ) << std::endl;
        std::cout << "Administrator Employee. Regular Pay: "
             << salary << std::endl;
        std::cout << "_________________________________________________\n";
    }
}//SavitchEmployees

