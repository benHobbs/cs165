#ifndef ADMINISTRATOREMPLOYEE_H
#define ADMINISTRATOREMPLOYEE_H

#include <string>
#include "salariedemployee.h"


namespace SavitchEmployees
{

    class AdministratorEmployee : public SalariedEmployee
    {
    public:
        AdministratorEmployee( );
        AdministratorEmployee (std::string theName, std::string theTitle,
                               std::string theSupervisor, std::string theSsn, std::string aor,
                               double theWeeklySalary);

        void setSupervisor(std::string newSupervisor);
        void setTitle(std::string newTitle);
        std::string getTitle();
        void setImmediateSupervisor(std::string newSupervisor);
        std::string getSupervisor();
        void setAreaOfResponsibility(std::string newAOR);
        std::string getAOR();
        void print();
        void printCheck();

    private:
        std::string adminTitle;
        std::string immediateSupervisor;
        std::string areaOfResponsibility;   //Production, Accounting, etc.
    };

}//SavitchEmployees

#endif //ADMINISTRATOREMPLOYEE_H
