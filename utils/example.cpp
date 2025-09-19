#include<iostream>

auto main() -> int {
	int array[] = {1, 2, 3, 4, 5};

	int* ans = std::begin(array);

	std::cout<<*ans<<std::endl;
}