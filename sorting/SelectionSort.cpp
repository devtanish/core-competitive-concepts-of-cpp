#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(int arr[], int n) {

    for(int i=0 ; i<n-1 ; i++){
        int minimum = i;
        for(int j=i+1 ; j<n ; j++){
            if(arr[minimum] > arr[j])
                minimum = j;
        }
        swap(arr[i], arr[minimum]);
    }

    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<"   ";
    }

    cout<<endl;

}   

int main() {

    int array[] = {2, 4, 1, 3, 8, 6, 7, 5};
    int size = sizeof(array)/sizeof(array[0]);
    SelectionSort(array, size);
    
}