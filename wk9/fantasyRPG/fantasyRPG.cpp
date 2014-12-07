/***************************************************************************************************
**	Author: Benjamin Hobbs
** 	Date Created: 3/5/2014
** 	Lab/Project#: Exercise 15 Problem 2
** 	Filename: fantasyRPG.cpp
** 	Overview: 	This program creates several creatures for a fantasy rpg.  This is done through the
**              use of inheritance, where each creature has a base class of baseCreature and then
**              (in the case of the demons a sub class baseDemon), and finally a creature specific
**              class.  The main program prints information about the creature and then shows 50
**              example attacks for that creature.
***************************************************************************************************/
#include "baseCreature.h"
#include "balrog.h"
#include "cyberdemon.h"
#include "elf.h"
#include "human.h"
#include <iostream>
#include <stdlib.h> //abs, rand
#include <time.h>   //Time, for randomization

using namespace fallen_fantasyRPG;

int main()
{
    srand(time(NULL));

    int damage;

    Human jim;
    jim.setStrength(15);    //jim is a strong human
    jim.BaseCreature::printInfo();
    std::cout << std::endl;
    for(int i = 0 ; i < 50 ; i++){
        damage = jim.getDamage();
    }
    std::cout << std::endl;

    Balrog roger;
    roger.BaseCreature::printInfo();
    std::cout << std::endl;
    for (int i = 0 ; i < 50 ; i++){
        damage = roger.getDamage();
    }
    std::cout << std::endl;

    Cyberdemon sid;
    sid.BaseCreature::printInfo();
    std::cout << std::endl;
    for (int i = 0 ; i < 50 ; i++){
        damage = sid.getDamage();
    }
    std::cout << std::endl;


    Elf willow;
    willow.BaseCreature::printInfo();
    std::cout << std::endl;
    for(int i = 0 ; i < 50 ; i++){
        willow.getDamage();
    }
    std::cout << std::endl;

    return 0;
}
