#ifndef HUMAN_H
#define HUMAN_H

#include "baseCreature.h"

#include <string>
#include <stdlib.h> //rand

namespace fallen_fantasyRPG
{
    class Human : public BaseCreature
    {
    public:
        Human()
            :BaseCreature(0,10,10)
        {
              /*  intentionally left blank    */
        }

        int getDamage()
        {
            int damage = BaseCreature::getBaseDamage();
            return damage;
        }
    };

}//fallen_fantasyRPG

#endif //HUMAN_H
