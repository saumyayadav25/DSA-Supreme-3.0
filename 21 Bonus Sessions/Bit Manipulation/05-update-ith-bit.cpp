#include<iostream>
using namespace std;

// 1. clear ith bit
// 2. target ko left shift i times and take OR

void clearIthBit(int n, int i){
    int mask = ~(1 << i);
    n = n & mask;
}

void updateIthBit(int n, int i, int target){
    clearIthBit(n,i);
    int mask = (target << i);
    n = n | mask;
    cout << "updated number: " << n << endl;
}

int main(){
    int n = 10; // 1010
    updateIthBit(n,0,1); //1011
    return 0;
}