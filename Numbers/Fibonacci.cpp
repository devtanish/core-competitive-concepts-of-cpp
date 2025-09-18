// Write a program to print the Fibonacci series up to n terms

#include<iostream>

void Fibnoacci(int a, int b, int target){

    int ans = a+b;

    if(b>=target) return;
    else {
        std::cout<<ans<<std::endl;
        return Fibnoacci(b, ans, target);
    }

}

auto main() -> int {
    int a = 0;
    int b = 1;

    int target = 40;

    Fibnoacci(a, b, target);
}