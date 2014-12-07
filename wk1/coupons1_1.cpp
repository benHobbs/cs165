/*******************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/14/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Programming Project 1.9
** 	Filename: videogame.cpp
**
** 	Overview: 	This program will tell you what you can do with some coupons
**				from a video game.  This version uses a while loop to accomplish
**				this task.
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
	
	int coupons, candyBars = 0, gumballs = 0;	//number of coupons
	
	std::cout << "Please enter # of coupons won: ";
	std::cin >> coupons;
	
	if (coupons == 0)
	{
		std::cout << "You have no coupons...you are sad." << std::endl;
		return 0;	
	}

	while (coupons > (price_candyBar - 1))	//candybar loop
	{
		candyBars++;
		coupons = coupons - price_candyBar;
	}
	
	while (coupons > (price_gumball - 1))	//gumball loop
	{
		gumballs++;
		coupons = coupons - price_gumball;
	}
	
		std::cout << "You can purchase:\n" << candyBars << " candy bars\n"
				  << gumballs << " gumballs\nAnd will have " << coupons
				  << " coupons remaining" << std::endl;
	
	return 0;
			  
}
