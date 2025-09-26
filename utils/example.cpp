#include <cstdio>
#include<vector>
#include<iostream>

#define LOG(x) std::cout<<x<<std::endl
void printValue(int x){
	LOG(x);
}	

void forEach(std::vector<int> vec, void(*fn)(int)){
	for(auto x : vec){
		fn(x);
	}
}

auto main() -> int {

	std::vector<int> array{1, 2,3, 4, 5};

	auto fn = printValue;

	std::cout<<fn<<std::endl;
	forEach(array, printValue);

}