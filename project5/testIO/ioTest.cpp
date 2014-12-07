#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv){

	int c, r;
	std::string filename = "startPos";

	std::ifstream ifs(filename.c_str());

	while (ifs >> c >> r){
		std::cout << c << "," << r << std::endl;
	}


	return 0;
}
