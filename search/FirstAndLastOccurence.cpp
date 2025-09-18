#include<iostream>
#include<vector>
using namespace std;

int FirstOccurence(vector<int> array, int key){
    int start = 0, index;
    int end = array.size()-1;
    int mid = ((start+end)/2);
    while(start<=end){
        mid = (start+end)/2;
        if(array[mid] == key){
            index = mid;
            end = mid-1;
        } else if(array[mid]<key){
            start = mid+1;
        } else if(array[mid]>key){
            end = mid-1;
        }
    }
    return index;
}

int LastOccurence(vector<int> array, int key){
    int start = 0, index;
    int end = array.size()-1;
    int mid = ((start+end)/2);
    while(start<=end){
        mid = (start+end)/2;
        if(array[mid] == key){
            index = mid;
            start = mid+1;
        } else if(array[mid]<key){
            start = mid+1;
        } else if(array[mid]>key){
            end = mid-1;
        }
    }
    return index;
}

int main(){
    vector<int> array = {1, 2, 3, 3, 3, 4, 4, 5};
    int key = 3;

    cout<<"First occurence of "<<key<<" is at the index of: "<<FirstOccurence(array, key)<<endl;
    cout<<"Last occurence of "<<key<<" is at the index of: "<<LastOccurence(array, key)<<endl;
}