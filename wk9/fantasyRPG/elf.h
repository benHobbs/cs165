#ifndef ELF_H
#define ELF_H

#include "baseCreature.h"

#include <string>
#include <stdlib.h> //rand

namespace fallen_fantasyRPG
{
    class Elf : public BaseCreature
    {
    public:
        Elf()
            :BaseCreature(3, 25, 8)
        {
              /*  intentionally left blank    */
        }

        int getDamage()
        {
            int damage = BaseCreature::getBaseDamage();
            if(rand()%100 < 10){
                std::cout << "Magical attack inflicts " << damage
                          << " points of additional damage." << std::endl;
                damage *= 2;
            }
            return damage;
        }
    };

}//fallen_fantasyRPG

#endif //ELF_H
