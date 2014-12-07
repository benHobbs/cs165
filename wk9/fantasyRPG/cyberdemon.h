#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include "baseDemon.h"

#include <string>
#include <stdlib.h> //rand

namespace fallen_fantasyRPG
{
    class Cyberdemon : public BaseDemon
    {
    public:
        Cyberdemon()
            :BaseDemon(1, 40, 20)
        {
              /*  intentionally left blank    */
        }

        int getDamage()
        {
            int damage = BaseDemon::getDemonDamage();
            return damage;
        }
    protected:

    private:

    };
}//fallen_fantasyRPG

#endif //CYBERDEMON_H
