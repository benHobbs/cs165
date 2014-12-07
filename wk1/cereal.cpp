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
	const float fMetricTon = 35273.92;		//in ounces
	float fCerealBox;				//user input 4 wt. of cereal box (ounces)
	float fCerealBoxInMT, fNumCerealBox4Ton;	//vars 4 calculations
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precesion(12);

	std::cout << "Please enter the weight of one box of cereal (in ounces): ";
	std::cin >> fCerealBox;		//get user input 4 wt.
	
	fCerealBoxInMT = fCerealBox / fMetricTon;	//calc. wt. of cereal box in MT

	fNumCerealBox4Ton = fMetricTon / fCerealBoxInMT;	//calc. num. of cereal boxes in MT
	
	std::cout << "Weight of cereal box in metric tons: "
			  << fCerealBoxInMT << "\n";				//print output 1
	std::cout << "Number of cereal boxes to make a metric ton: "
			  << (int) fNumCerealBox4Ton << std::endl;		//print output 2
			  
	return 0;
}
