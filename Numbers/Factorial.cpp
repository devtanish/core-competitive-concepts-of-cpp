// Find the factorial of a number using recursion.

#include<iostream>

int Factorial_using_forLoop(int number){
    int ans = 1;
    for(int i=1 ; i<=number ; i++){
        ans *= i;
    }

    return ans;
}

int factorial_using_recursion(int number){
    if(number <= 1) return 1;
    else return number * factorial_using_recursion(number-1);
}

auto main() -> int {
    unsigned int number{7};

    std::cout<<Factorial_using_forLoop(number)<<std::endl;
    std::cout<<factorial_using_recursion(number)<<std::endl;
}