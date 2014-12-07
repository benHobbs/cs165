/*******************************************************************************
**	Author: Benjamin Hobbs
** 	Modified by: n/a
** 	Date Created: 1/13/2014
** 	Last Modification Date: n/a
** 	Lab/Project#: Programming Project 1.1
** 	Filename: cereal.cpp
**
** 	Overview:	A program that will read the weight of a package of breakfast
**				cereal in ounces and output the weight in metric tons as well
**				as well as the number of boxes needed to yield one metric ton
**				of cereal.	  	
**
** 	Input:		User Input (weight of cereal package)
**
** 	Output:		|	1	Weight of cereal box in metric tons
**				|	2	# of boxes to make a metric ton
**
********************************************************************************/

#include <iostream>
int main() {
	int iTest;

	for (int i = 0 ; i < 10 ; i++ ) {
		std::cin >> iTest;
		std::cout << i << std::endl;
	}
			  
	return 0;
}
