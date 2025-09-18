// Implement a program to sort an array using Bubble Sort / Selection Sort / Insertion Sort

#include<iostream>
#include<vector>

template<typename T> void Bubble_Sort(std::vector<T>& array){
    for(int i=0 ; i<array.size() ; i++)
        for(int j=1 ; j<array.size()-i ; j++)
            if(array[j-1]>array[j])
                std::swap(array[j-1], array[j]);
}

template<typename T> void Selection_Sort(std::vector<T>& array){
    for(int i=0 ; i<array.size()-1 ; i++){
        for(int j=i+1 ; j<array.size() ; j++)
            if(array[i]>array[j]) std::swap(array[i], array[j]);
    }
}

template<typename T> void Insertion_Sort(std::vector<T>& array) {
    for (int i = 1; i < array.size(); i++) {
        T key = array[i];      
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

auto main() -> int {
    std::vector<int> array{1, 5, 4, 3, 2, 7, 6, 9, 8};

    Insertion_Sort(array);

    for(auto x : array){
        std::cout<<x<<"   ";
    }
    std::cout<<std::endl;
}