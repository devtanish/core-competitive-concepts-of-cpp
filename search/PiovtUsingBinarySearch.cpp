#include<iostream>
#include<vector>
using namespace std;

int peakMountainIndex(vector<int> array){
    int start = 0;
    int end = array.size()-1;
    int mid = (start+end)/2;
    while(start<end){
        if(array[mid] >= array[0]){
            start = mid+1;
        } else {
            end = mid;
        }
        mid = (start+end)/2;
    }
    return start;
}

int main() {
    vector<int> array = {7, 8, 1, 2, 3, 4};

    cout<<peakMountainIndex(array)<<endl;
}