#include<iostream>
using namespace std;

void clearLastIBits(int n, int i){
    int mask = (-1 << i);
    n = n & mask;
    cout << "updated number: " << n << endl;
}

int main(){
    int n = 15; // 1111
    clearLastIBits(n,3); //1000 -> 8
    return 0;
}