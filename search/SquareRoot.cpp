#include<iostream>
#include<vector>
using namespace std;

int squareRoot(int number){
    int start = 0;
    int end = number/2;
    int mid = (start+end)/2;

    for(int i=1 ; i<number/2 ; i++){
        mid = (start+end)/2;
        if(mid*mid == number){
            return mid;
        } else if(mid*mid > number){
            end = mid -1;
        } else {
            start = mid +1;
        }
    }
    return mid;
}

double impoveVersion(int number, int precedence, int tempSol){
    double factor = 1;
    double ans=tempSol;

    for(int i=0 ; i<precedence ; i++){
        factor = factor/10;
        for(double j=ans ; j*j<number ; j=j+factor){
            ans = j;
        }
   }
   return ans;
}

int main() {
    int number = 37;
    
    int tempSol = squareRoot(number);
    cout<<impoveVersion(number , 3 , tempSol)<<endl;
}