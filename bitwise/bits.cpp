#include<iostream>
#include<bitset>
#include<unordered_map>
#include<string>

auto main() -> int {
    std::string name = "Tanish";
    std::unordered_map<char, std::bitset<8>> bits;
    {
        int i=name.length()-1;
        while(i >= 0){
            bits[name[i]] = std::bitset<8>(static_cast<unsigned long long>(name[i]));
            i--;
        }
    }  

    for(const auto& [ch, bit] : bits){
        std::cout<<ch<<": "<<bit<<std::endl;
    }

    std::cout<<std::endl;


    // std::cout<<number<<std::endl;
}