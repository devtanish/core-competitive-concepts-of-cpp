#include<iostream>
#include<vector>
using namespace std;

bool LinearSearch(vector<int> array, int size, int key){
    bool have = false;
    for(int i=0 ; i<size ; i++){
        if(array[i] == key){
            have = true;
        }
    }
    return have;
}

int main() {
    vector<int> array = {1, 4, 2, 6, 5, 8, 7, 9, 3};
    int size = array.size();
    int key = 1;
    cout<<LinearSearch(array, size, key)<<endl;
}