// Find the sum of digits of a number until the sum becomes a single digit

#include<iostream>

int sumOfDigit(int number){
    int ans = 0;

    while(number>=1){
        ans += number%10;
        number /= 10;
    }

    return ans;
}

auto main() -> int {
    int number = 1234;

    std::cout<<sumOfDigit(number)<<std::endl;
}