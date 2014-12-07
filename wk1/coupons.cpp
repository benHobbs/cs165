/*******************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/14/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Programming Project 1.9
** 	Filename: videogame.cpp
**
** 	Overview: 	This program will tell you what you can do with some coupons
**				from a video game.
**
** 	Input:		User Input - # of coupons
**
** 	Output:		Number of candy bars and gumballs you will get
**
********************************************************************************/
//Macros
#include <iostream>
int main() {
	const int price_gumball = 3;	//define the price, in coupons, of gumball
	const int price_candyBar = 10;	//define the price, in coupons, of candybar
	
	int coupons, candyBars, gumballs;	//number of coupons
	
	std::cout << "Please enter # of coupons won: ";
	std::cin >> coupons;
	
	if (coupons >= price_candyBar) {
		candyBars = coupons / price_candyBar;	//no need to cast, will auto_round
		gumballs = (coupons % price_candyBar) / price_gumball;	//get num of gumballs
		coupons =  coupons - ((candyBars * price_candyBar) + (gumballs * price_gumball));
	
		std::cout << "You can purchase:\n" << candyBars << " candy bars\n"
				  << gumballs << " gumballs\nAnd will have " << coupons
				  << " coupons remaining" << std::endl;
	}
	else {
		std::cout << "You are unable to purchase anything...you are sad.\n"
				  << "On the plus side, you have "
				  << coupons << " coupons remaining.\n";
	}
	
	return 0;
			  
}