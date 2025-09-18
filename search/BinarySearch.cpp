#include<iostream>
#include<algorithm>
using namespace std;

int BinarySearch(int array[], int size, int key){
    int start = 0;
    int end = size-1;

    int mid = (start+end)/2;

    while(start<=end){
        if(array[mid] == key){
            return mid;
        } else if(array[mid]<key){
            start = mid+1;
        } else {
            end = mid-1;
        }

        mid = (start+end)/2;
    }

    return -1;
}

int main() {
    int array[] = {4, 6, 5, 2, 3, 1, 8, 7, 9};
    int size = sizeof(array) / sizeof(array[0]);
    int key = 22;

    sort(array, array+size);
    cout<<"the index value of "<<key<<" is "<<BinarySearch(array, size, key)<<endl;

}
