// Create a program that checks whether two strings are anagrams

#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<vector>

 std::bitset<8UL> getBit(const std::string& str){
    std::bitset<8> bit = 0;

    for(int i=0 ; i<str.length() ; i++){
        bit = bit | std::bitset<8>(static_cast<unsigned long long>(str[i]));
    }

    return bit;
}

auto main() -> int {
    std::string str = "Tanish";
    std::string str2 = "isahnT";

    std::cout<<getBit(str)<<std::endl;
    std::cout<<getBit(str)<<std::endl;
    
}