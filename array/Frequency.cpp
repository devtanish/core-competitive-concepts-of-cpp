// Implement a function to find the frequency of each element in an array

#include <iostream>
#include <vector>
#include <unordered_map>

template<typename T>
std::unordered_map<T, int> frequency(const std::vector<T>& array) {
    std::unordered_map<T, int> freq;
    for (const auto& x : array) {
        freq[x] = freq[x] + 1;
        // freq[x]++;
    }
    return freq;
}

int main() {
    std::vector<int> array{1, 4, 3, 3, 1, 6, 8, 3, 8};

    auto freqMap = frequency(array);

    for (auto& pair : freqMap) {
        std::cout << pair.first << " appears " << pair.second << " times\n";
    }

    return 0;
}
