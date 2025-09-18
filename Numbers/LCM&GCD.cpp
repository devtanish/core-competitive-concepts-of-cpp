// Count the number of vowels, consonants, digits, and spaces in a string

#include<iostream>
#include<vector>
#include<cmath>

std::vector<std::pair<int, int>> iterate(int num1){
    std::vector<std::pair<int, int>> cal;

    int i=2;
    while(num1 != 1){
        if(num1%i == 0){
            num1 /= i;
            cal.push_back({i, num1});
            i = 2;
        } else {
            i++;
        }
    }

    return cal;
}

int GCD(int num1, int num2){
    std::vector<std::pair<int, int>> it1 = iterate(num1);
    std::vector<std::pair<int, int>> it2 = iterate(num2);
    
    int ans = 1;
    
    for(int i=0 ; i < std::min(it1.size(), it2.size()) ; i++){
        if(it1[i].first == it2[i].first){
            ans *= it1[i].first;
        }
    }
    
    return ans;
}

int GCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

auto main() -> int {
    int num1 = 1022;
    int num2 = 988;

    std::cout<<GCD(num1, num2)<<std::endl;
}