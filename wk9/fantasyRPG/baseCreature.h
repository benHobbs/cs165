#ifndef BASECREATURE_H
#define BASECREATURE_H

#include <iostream>
#include <string>
#include <stdlib.h> //rand

namespace fallen_fantasyRPG
{
    class BaseCreature
    {
    public:
        BaseCreature()
        {
            type = 0, strength = 10, hitpoints = 10;    //initialize to human
        }

        BaseCreature(int iType, int iStr, int iHP)
        {
            type = iType, strength = iStr, hitpoints = iHP;
        }

        void setType(int newType){ type = newType; };
        int getType(){ return type; };
        void setStrength(int newStr){ strength = newStr; };
        int getStrength(){ return strength; };
        void setHitPoints(int newHP){ hitpoints = newHP; };
        int getHitPoints(){ return hitpoints; };

        void printInfo(){
            std::cout << "Type: " << getSpecies() << "\nStrength: " << getStrength() << "\nHP: "
                      << getHitPoints() << std::endl;
        }

        int getBaseDamage() //returns damage where 0 < damage <= strength
        {
            int damage = (rand() % strength + 1);

            std::cout << "The " << getSpecies() << " hits for " << damage << " points!"
                      << std::endl;

            return damage;
        }

        std::string getSpecies()
        {
            switch (type)
            {
            case 0: return "Human";
            case 1: return "Cyberdemon";
            case 2: return "Balrog";
            case 3: return "Elf";
            }
            return "Unknown";
        }
    private:
        int type; // 0 human, 1 cyberdemon, 2 balrog, 3 elf
        int strength;
        int hitpoints;
    };
}//fallen_fantasyRPG

#endif //BASECREATURE_H
