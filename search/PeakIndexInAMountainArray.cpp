#include<iostream>
#include<vector>
using namespace std;

int peakMountainIndex(vector<int> array){
    int start = 0;
    int end = array.size()-1;
    int mid = (start+end)/2;
    while(start<end){
        mid = (start+end)/2;
        if(array[mid]<array[mid+1]){
            start = mid;
        } else if(array[mid-1]>array[mid]){
            end = mid;
        } else {
            break;
        }
    }
    return mid;
}

int main() {
    vector<int> array = {1, 3, 4, 5, 1};

    cout<<array[peakMountainIndex(array)]<<endl;
}