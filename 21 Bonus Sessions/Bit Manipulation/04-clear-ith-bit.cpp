#include<iostream>
using namespace std;

// left shift i times and take not

void clearIthBit(int n, int i){
    int mask = ~(1 << i);
    n = n & mask;
    cout << "Updated number: " << n << endl;
}

int main(){
    int n = 10; // 1010
    clearIthBit(n,3); // 0010
    return 0;
}