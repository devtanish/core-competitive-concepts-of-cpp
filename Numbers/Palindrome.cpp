// Write a program to check if a string is a palindrome

#include<iostream>
#include<string>

bool palindrome(const std::string& str) {
    int n = str.length();
    for(int i = 0; i < n / 2; i++) {
        if(str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str = "naman";
    if(palindrome(str)) 
        std::cout << "Palindrome" << std::endl;
    else 
        std::cout << "Not Palindrome" << std::endl;
}
