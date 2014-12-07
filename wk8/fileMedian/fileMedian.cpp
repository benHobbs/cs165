/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   3/1/2014
 ** Lab/Project#:   Ex. 14, 1a & b
 ** Filename:       fileMedian.cpp
 ** Overview: 	    This program takes the values (in this case unordered integers that are space
 **                 separated), and returns the median and all the quartiles of same values.
 ** References:     http://www.mathsisfun.com/data/quartiles.html
***************************************************************************************************/
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>

int readFile(std::string filename, std::vector<int> &v);
void printVector(std::vector<int> v);
double median(std::vector<int> v);
void quartiles(std::vector<int> v, double &quartile1, double &quartile2, double &quartile3);

int main(int argc, char **argv){
    double q1 = 0, q2 = 0, q3 = 0;
    int elems = 0;
    std::string filename = "ints.txt";
    std::vector<int> v;

    if(elems = readFile(filename,v) > 4){
        std::cout << filename << " contents: ";
        printVector(v);
        std::cout << "Median: " << median(v) << std::endl;
        quartiles(v, q1, q2, q3);
        std::cout << "Quartile 1: " << q1 << "\nQuartile 2: " << q2
                  << "\nQuartile 3: " << q3 << std::endl;
    }
    else if(elems > 0 && elems < 5){
        std::cout << "There are too few elements in " << filename << " to do this operation.\n";
    }
    else if(elems ==0){
        std::cout << "File is empty.\n";
    }

    return 0;
}

/**************************************************************************************************
 ** Function:       int readFile(std::string filename, std::vector<int> &v)
 ** Description:    Reads file into vector, if file does not exist returns -1.  Will return empty
 **                 vector if file has something other than integers.
 *************************************************************************************************/
int readFile(std::string filename, std::vector<int> &v){

    std::ifstream ifs(filename.c_str());

    if (ifs) {
        int input = 0;
        while (ifs >> input){
            v.push_back(input);
        }
        std::sort(v.begin(),v.end());	//sort ints
    }else{
        std::cout << "Unable to read file.";
        return -1;
    }

    return v.size();
}

/**************************************************************************************************
 ** Function:       void printVector(std::vector<int> v)
 ** Description:    Prints the vector.
 *************************************************************************************************/
void printVector(std::vector<int> v){
    for (unsigned int i = 0 ; i < v.size() ; i++){	//print vector
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

/**************************************************************************************************
 ** Function:       double median(std::vector<int> v)
 ** Description:    Return median (as double) when given a vector of n > 4 elements.
 *************************************************************************************************/
double median(std::vector<int> v){
    if((v.size()%2!=0) && v.size()>0){  //odd num elems
        return double(v[v.size() / 2]);
    }
    else {  //even num elems
        return (double(v[(v.size() / 2)-1]) + double(v[(v.size() / 2)])) / 2;
    }
}

/**************************************************************************************************
 ** Function:       void quartiles(std::vector<int> v, double &quartile1, double &quartile2,
 **                 double &quartile3)
 ** Description:    Returns (by ref) the quartile values
 *************************************************************************************************/
void quartiles(std::vector<int> v, double &quartile1, double &quartile2, double &quartile3){
    quartile2 = median(v);
    std::vector<int> q1, q3;

    if(v.size()%2!=0){  //odd num elems
        for(int i = 0 ; i < v.size()/2 ; i++){
            q1.push_back(v[i]);
            q3.push_back(v[i+v.size()/2+1]);
        }
    }
    else {  //even num elems
        for(int i = 0 ; i <= v.size()/2 - 1 ; i++){
            q1.push_back(v[i]);
            q3.push_back(v[i+v.size()/2]);
        }
    }
    quartile1 = median(q1);
    quartile3 = median(q3);
}
