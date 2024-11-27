#include<iostream>
using namespace std;

// TC: O(logB)
int fastExponentiation(int a, int b){
    int ans = 1;
    while(b>0){
        if(b&1) ans = ans * a;   //odd
        a = a * a;
        b >>= 1;    //b=b/2
    }
    return ans;
}

int main(){
    cout << fastExponentiation(5,4);
    return 0;
}