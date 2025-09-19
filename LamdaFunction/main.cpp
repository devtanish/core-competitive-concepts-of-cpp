#include<iostream>
#include<functional>

auto main() -> int {

    int value = 20;
    int value2 = 10;

    auto add = [&](int a, int b) -> int {
        return value + value2;
    };

    std::function<std::function<int(int, int)>()> nestedAdd = []() -> std::function<int(int, int)> {
        return [=](int a, int b){
            return a+b;
        };
    };

    std::cout<<nestedAdd()(1, 2)<<std::endl;

    std::cout<<add(1, 2)<<std::endl;

    return 0;
}