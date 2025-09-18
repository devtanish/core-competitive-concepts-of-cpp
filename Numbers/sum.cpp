// Implement a simple calculator using switch-case

#include<iostream>

template<typename... Args>
int sum(Args... args) {
    return (args + ...);
}

auto main() -> int {
    std::cout<<sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}