#ifndef BASEDEMON_H
#define BASEDEMON_H

#include "baseCreature.h"

#include <string>
#include <stdlib.h> //rand

namespace fallen_fantasyRPG
{
    class BaseDemon : public BaseCreature
    {
    public:
        BaseDemon(int iType, int iStr, int iHP)
                    :BaseCreature(iType, iStr, iHP)
        {
            /*  intentionally left blank    */
        }
        int getDemonDamage()
        {
            int damage = BaseCreature::getBaseDamage();
                if (rand()%100 < 5){    //added damage
                    std::cout << "Demonic attack inflicts 50 additional damage points!"
                              << std::endl;
                    damage += 50;
                }
            return damage;
        }
    };
}//fallen_fantasyRPG

#endif //BASEDEMON_H
