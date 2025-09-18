#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> array1, vector<int> array2) {
    vector<int> ans;
    int i = 0, j = 0;

    // Merge elements in sorted order
    while (i < array1.size() && j < array2.size()) {
        if (array1[i] < array2[j]) {
            ans.push_back(array1[i]);
            i++;
        } else {
            ans.push_back(array2[j]);
            j++;
        }
    }

    // Add remaining elements from array1
    while (i < array1.size()) {
        ans.push_back(array1[i]);
        i++;
    }

    // Add remaining elements from array2
    while (j < array2.size()) {
        ans.push_back(array2[j]);
        j++;
    }

    return ans;
}

int main() {
    vector<int> array1 = {1, 4, 6, 7, 8};
    vector<int> array2 = {2, 3, 5, 9, 10, 11, 76, 98};

    vector<int> mergedArray = merge(array1, array2);

    // Print merged array
    for (int i = 0; i < mergedArray.size(); i++) {
        cout << mergedArray[i] << " ";
    }

    return 0;
}
