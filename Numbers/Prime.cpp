// Check whether a given number is prime or not.

#include<iostream>
#include<algorithm>
#include<cmath>

bool isPrimeNumber(int number) {
    if(number < 2) return false;
    for(int i=2 ; i<=sqrt((int)number) ; i++){
        if(number%i == 0)
            return false;
    }
    return true;
}

auto main() -> int {
    unsigned int number;

    std::cout<<"Find the number is prime or not: "; std::cin>>number;

    isPrimeNumber(number) ? std::cout<<std::endl<<number<<" is a prime number"<<std::endl : std::cout<<std::endl<<number<<" is not a prime number"<<std::endl;
}