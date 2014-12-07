/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   3/1/2014
 ** Lab/Project#:   Ex. 14, problem 2
 ** Filename:       fileMerge.cpp
 ** Overview: 	    This program takes the values from two files and writes them into a third file.
***************************************************************************************************/
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>

/**************************************************************************************************
 ** Class:          ifstream_imp
 ** Description:    Constructs ifstream object and stores file name, closes stream on destruct
 *************************************************************************************************/
class ifstream_imp
{
public:
    ifstream_imp(std::string file){ //constructor opens stream
        filename = file.c_str();
        ifs.open(filename);
    }
    ~ifstream_imp(){ ifs.close(); } //destructor closes stream

    std::ifstream ifs;
    std::string filename;
};

/**************************************************************************************************
 ** Class:          ofstream_imp
 ** Description:    Constructs ofstream object and stores file name, closes stream on destruct
 *************************************************************************************************/
class ofstream_imp
{
public:
    ofstream_imp(std::string file){
        filename = file.c_str();
        ofs.open(filename);
    }
    ~ofstream_imp(){ ofs.close(); } //destructor closes stream

    std::ofstream ofs;
    std::string filename;
};


/**************************************************************************************************
 ** Main and Accompanying Functions
 *************************************************************************************************/
void mergeFiles(ofstream_imp &ofs, ifstream_imp &ifs_1, ifstream_imp &ifs_2);
std::string readFile(ifstream_imp &ifs, std::vector<int> &v);
void printVector(ofstream_imp &ofs, std::vector<int> v);

int main(int argc, char **argv){
    std::string filename1 = "a.txt", filename2 = "b.txt", outputfile = "output";

    ifstream_imp ifs_1(filename1), ifs_2(filename2);

    ofstream_imp ofs(outputfile);

    mergeFiles(ofs, ifs_1, ifs_2);

    return 0;
}

/**************************************************************************************************
 ** Function:       void mergeFiles(ofstream_imp &ofs, ifstream_imp &ifs_1, ifstream_imp &ifs_2)
 ** Description:    Sends each file to readFile, outputs status
 *************************************************************************************************/
void mergeFiles(ofstream_imp &ofs, ifstream_imp &ifs_1, ifstream_imp &ifs_2){
    std::vector<int> v;

    std::cout << readFile(ifs_1,v);
    std::cout << readFile(ifs_2,v);
    std::sort(v.begin(),v.end());
    printVector(ofs, v);
    return;
}

/**************************************************************************************************
 ** Function:       int readFile(ifstream_imp &ifs, std::vector<int> &v){
 ** Description:    Reads file into vector, if file does not exist returns -1.  Will return empty
 **                 vector if file has something other than integers.
 *************************************************************************************************/
std::string readFile(ifstream_imp &ifs, std::vector<int> &v){
    std::string out = ifs.filename;
    if (ifs.ifs) {
        int input = 0, ct = 0;
        while (ifs.ifs >> input){
            v.push_back(input);
            ct++;
        }
        if (ct > 0){
            out += ": read successful\n";
            return out;
        }
        else if(ct == 0){
            out += ": read successful - 0 recognized elements\n";
            return out;
        }
        else{
            out += ": read unsuccessful - check if file exists";
            return out;
        }
    }
}

/**************************************************************************************************
 ** Function:       void printVector(ofstream_imp &ofs, std::vector<int> v)
 ** Description:    Prints the vector to ofs
 *************************************************************************************************/
void printVector(ofstream_imp &ofs, std::vector<int> v){
    for (unsigned int i = 0 ; i < v.size() ; i++){	//print vector
        ofs.ofs << v[i] << " ";
    }
    ofs.ofs << std::endl;
    std::cout << ofs.filename << " : print successful" << std::endl;
}
