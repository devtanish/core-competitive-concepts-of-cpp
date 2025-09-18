#include<iostream>

auto main() -> int {

    int value = 20;
    int value2 = 10;

    auto add = [&](int a, int b) -> int {
        return value + value2;
    };

    std::cout<<add(1, 2)<<std::endl;

    return 0;
}