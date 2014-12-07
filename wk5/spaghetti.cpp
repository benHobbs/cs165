/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/5/2014
 ** Lab/Project#:   Ex. 9 Problem 1
 ** Filename:       spaghetti.cpp
 ** Overview: 	    This program does all of the things in Exercise Set 9 steps 1 - 4.  In order.
 ** Input:  		none
 ** Output: 		Name and age, then age after birthday member function is called
 ** References:		http://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
***************************************************************************************************/

#include <iostream>	    //std::cout, std::cin
#include <string>	    //std::string

class Person{
public:
    Person(std::string nameValue, int ageValue);   //constructor
    void havingBirthday( void );
    int get_age( void );
    std::string get_name( void );
private:
    std::string name;
    int age;
};

Person::Person(std::string nameValue, int ageValue)
                    : name(nameValue), age(ageValue)
{/*left blank*/}

void Person::havingBirthday( void ){
    age++;
}

int Person::get_age( void ){
    return age;
}

std::string Person::get_name( void ){
    return name;
}

int main(){
    Person myself("Some Dude",29);

    std::cout << myself.get_name() << " you are " << myself.get_age() << " years old!"
              << std::endl;

    myself.havingBirthday();

    std::cout << "Congratulations " << myself.get_name() << " you had a birthday, you are now "
              << myself.get_age() << " years old!" << std::endl;

    return 0;
}
