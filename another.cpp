#include<iostream>
#include<unordered_map>
#include<vector>

template<typename T> std::unordered_map<T, int> frequency(std::vector<T> array){
    std::unordered_map<T, int> freq;

    for(const T& x : array){
        freq[x]++;
    }

    return freq;
}

auto main() -> int {

    std::vector<int> array{1, 4, 3, 3, 1, 6, 8, 3, 8}; 

    auto ans = frequency(array);

    for(const auto& [value , frequency] : ans){
        std::cout<<value<<" appers: "<<frequency<<std::endl;
    }

}