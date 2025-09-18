// Count the number of vowels, consonants, digits, and spaces in a string

#include<iostream>
#include<string>
#include<unordered_set>

class Count{
    private:
        std::string str;

    public:

        Count(std::string Str) : str(Str){};

        int vowels(){
            int numberOfVowels = 0;
            std::unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            
            for(auto ch : str){
                if (vowelSet.count(ch)) {
                    numberOfVowels++;
                }
            }
            return numberOfVowels;
        }

        int consonants(){
            int count = 0;
            std::unordered_set<char> vowelSet = {'a','e','i','o','u','A','E','I','O','U'};
            for (auto ch : str) {
                if (isalpha(ch) && !vowelSet.count(ch)) {
                   count++;
                }
            }
            return count;
        }

        int digits(){
            int numberOfDigits = 0;
            std::unordered_set<char> findDigit = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            for(auto x : str){
                if(findDigit.count(x)){
                    numberOfDigits++;
                }
            }
            return numberOfDigits;
        }

        int space(){
            int Spaces = 0;
            for(auto x : str){
                if(x == ' ') Spaces++;
            }
            return Spaces;
        }
};

auto main() -> int {
    std::string name = " Tanish ";
    Count co(name); 

    std::cout<<"number of vowels exist in "<<name<<" is: "<<co.vowels()<<std::endl;
    std::cout<<"number of consonants exist in "<<name<<" is: "<<co.consonants()<<std::endl;
    std::cout<<"number of digits exist in "<<name<<" is: "<<co.digits()<<std::endl;
    std::cout<<"number of spaces exist in "<<name<<" is: "<<co.space()<<std::endl;

}