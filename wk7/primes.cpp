/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/21/2014
 ** Lab/Project#:   Ex. 13 Problem 3
 ** Filename:       primes.cpp
 ** Overview:       This class
 ** References:     http://en.wikipedia.org/wiki/Primality_test
***************************************************************************************************/
#include <iostream>
#include <math.h>   /* square root - sqrt */


class PrimeNumber
{
public:
    //constructors
    PrimeNumber(){ prime = 2; }   //default constructor
    PrimeNumber(int primeNumber){
        if(isPrime(primeNumber)){ prime = primeNumber; }    //verify prime entry
        prime = 2;
    }

    //Mutator
    void setPrime(int primeNumber){ prime = primeNumber; }

    //Accessor
    int getPrime(){ return prime; }

    //Member functions
    int nextPrime();
    int lastPrime();
    bool isPrime(int num);
    bool isEven(int num);

    //Operator Overloads
    PrimeNumber operator++(int regardless){
        setPrime(nextPrime());
        return prime; }
    PrimeNumber operator++(){
        setPrime(nextPrime());
        return prime; }
    PrimeNumber operator--(int regardless){
        setPrime(lastPrime());
        return prime; }
    PrimeNumber operator--(){
        setPrime(lastPrime());
        return prime; }
private:
    int prime;  //prime number
};

/**************************************************************************************************
 ** Function:       int PrimeNumber::nextPrime()
 ** Description:    Returns closest prime number above currently stored prime.
 *************************************************************************************************/
int PrimeNumber::nextPrime(){
    int nextPrime = prime + 1;

    if(nextPrime<=2){
        return 2;
    }
    while (isPrime(nextPrime)==false){
        nextPrime++;
    }
    return nextPrime;
}

/**************************************************************************************************
 ** Function:       int PrimeNumber::lastPrime()
 ** Description:    Returns closest prime number below currently stored prime.
 *************************************************************************************************/
int PrimeNumber::lastPrime(){
    int lastPrime = prime - 1;

    if(lastPrime<=2){
        return 2;
    }
    while (isPrime(lastPrime)==false){
        lastPrime--;
    }
    return lastPrime;
}

/**************************************************************************************************
 ** Function:       PrimeNumber::isPrime(int num)
 ** Description:    Returns true if int num is a prime.
 *************************************************************************************************/
bool PrimeNumber::isPrime(int num){
    if(isEven(num)){
        return false;
    }
    for (int divisor = 2 ; divisor <= (int(sqrt(num))+1) ; divisor++){
        if(num % divisor == 0){
            return false;
        }
    }
    return true;
}

/**************************************************************************************************
 ** Function:       PrimeNumber::isEven(int num)
 ** Description:    Returns true if int num is an even number.
 *************************************************************************************************/
bool PrimeNumber::isEven(int num){
    return (num % 2 == 0);
}


/**************************************************************************************************
 ** Main and Functions ****************************************************************************
 *************************************************************************************************/

void testBasic(int seedPrime);
void testLessBasic(int seedPrime);

int main(){
    testBasic(1);
    testLessBasic(1);

    return 0;
}

void testBasic(int seedPrime){
    PrimeNumber prime(seedPrime);  //init PrimeNumber Object

    std::cout << "Seed Value is:" << prime.getPrime() << std::endl << std::endl;
    ++prime;
    std::cout << "++prime = " << prime.getPrime() << std::endl;
    prime++;
    std::cout << "prime++ = " <<  prime.getPrime() << std::endl;
    --prime;
    std::cout << "--prime = " <<  prime.getPrime() << std::endl;
    prime--;
    std::cout << "prime-- = " <<  prime.getPrime() << std::endl;

}

void testLessBasic(int seedPrime){
    PrimeNumber prime(seedPrime);

    std::cout << "\n\nFirst 500 Primes\n\n";
    for (int i = 0 ; i <= 499 ; i++){
        if (i%10==0){ std::cout << std::endl; }
        std::cout << prime.getPrime() << "\t";
        prime++;
    }
    std::cout << std::endl;
}


