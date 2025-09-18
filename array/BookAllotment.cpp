#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumAlloat(vector<int> array){
    vector<int> ans;
    for(int i=0 ; i<array.size()-1 ; i++){
        int p1=i , p2=array.size()-1-i;
        int ans1=0 , ans2=0;
        for(int j=0 ; j<array.size(); j++){
            if(p1>=j){
                ans1 += array[j];
            } else {
                ans2 += array[j];
            }
        }
        ans.push_back(max(ans1, ans2));
    }
    return *min_element(ans.begin(), ans.end());
}


int main() {
    vector<int> array = {10, 20, 30, 40};

    // cout<<minimumAlloat(array)<<endl;
    cout<<minimumAlloat(array);
}