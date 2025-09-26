#include <cstddef>
#include <iostream>
#include <array>
#include <algorithm> // for std::reverse

template<typename T, size_t N>
void rotateArray(std::array<T, N>& array, int key){
    key = key % N;
    if(key == 0) return;

    std::reverse(array.begin(), array.begin()+key);
    std::reverse(array.begin()+key, array.end());
    std::reverse(array.begin(), array.end());
}

auto main() -> int {
    std::array<int, 5> arr{1, 2, 3, 4, 5};
    int k = 2;

    rotateArray(arr, k);

    for (auto x : arr) {
        std::cout << x << "   ";
    }
    std::cout << "\n";

    return 0;
}
