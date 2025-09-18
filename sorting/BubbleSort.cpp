#include<iostream>
#include<vector>
#include<string>
using namespace std;

void bubbleSort(int arr[], int size){

    for(int i=1 ; i<size ; i++){
        bool swaped = false;
        for(int j=0 ; j<size-i ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swaped = true;
            }
        }
        if(swaped == false){
            break;
        }
    }

    for(int i=1 ; i<size ; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int main() {
    
    int array[] = {2, 4, 1, 3, 8, 6, 7, 5};
    int size = sizeof(array)/sizeof(array[0]);
    bubbleSort(array, size);
}