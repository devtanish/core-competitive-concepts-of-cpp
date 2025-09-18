#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void moveZero(int array[], int size){
    int noneZero = 0;

    sort(array, array + size);

    for(int i=0 ; i<size ; i++){
        if(array[i] != 0){
            swap(array[i], array[noneZero]);
            noneZero++;
        }
    }
}

void printArray(int array[], int size){
    for(int i=0 ; i<size ; i++){
        cout<<array[i]<<"  ";
    }
}

int main(){
    int array[] = {2, 1, 5, 4, 9, 0, 4, 0, 6, 0, 0, 2};
    int size = sizeof(array)/sizeof(array[0]);

    moveZero(array, size);
    printArray(array, size);
    cout<<endl;
}