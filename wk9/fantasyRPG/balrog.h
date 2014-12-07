#ifndef BALROG_H
#define BALROG_H

#include "baseDemon.h"

#include <string>
#include <stdlib.h> //rand

namespace fallen_fantasyRPG
{
    class Balrog : public BaseDemon
    {
    public:
        Balrog()
            :BaseDemon(2, 20, 50)
        {
              /*  intentionally left blank    */
        }

        int getDamage()
        {
            int damage1 = BaseDemon::getDemonDamage();

            std::cout << "The Balrogs speed allows for a second attack...";
            int damage2 = BaseCreature::getBaseDamage();

            return damage1 + damage2;
        }
    };
}//fallen_fantasyRPG

#endif //BALROG_H
