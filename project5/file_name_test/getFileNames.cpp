#include <fstream>
#include <string>
#include <dirent.h>
#include <vector>
#include <iostream>
#include <algorithm>
	
std::vector<std::string> open(std::string path = ".") {
	DIR* dir;
	dirent* pdir;
	std::vector<std::string> files;
	
	dir = opendir(path.c_str());

	while (pdir = readdir(dir)){
		std::string str = pdir->d_name;		
		
		if (str.at(0) != '.'){	//make sure valid file
			files.push_back(pdir->d_name);}
	}

	std::sort(files.begin(),files.end());	//sort files

	return files;
}



int main(){
	std::vector<std::string> f;

	f = open("seeds");	//"seeds"
 

	for (unsigned int i = 0 ; i < f.size() ; i++){
		std::cout << f[i] << std::endl;
	}

	return 0;
}
