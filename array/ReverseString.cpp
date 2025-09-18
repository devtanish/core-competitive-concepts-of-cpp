// Reverse a given string without using built-in functions

#include<iostream>
#include<string>

void ReverseStr(std::string &str){
    for(int i=0 ; i<(str.length())/2 ; i++){
        std::swap(str[i], str[str.length()-i-1]);
    }
}

auto main() -> int {
    std::string str = " hsinaT  ";

    ReverseStr(str);

    std::cout<<str<<std::endl;
}