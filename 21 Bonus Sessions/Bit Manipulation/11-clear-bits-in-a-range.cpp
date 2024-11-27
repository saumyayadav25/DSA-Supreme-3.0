#include<iostream>
using namespace std;

void clearBitsInRAnge(int n, int i, int j){
    int a = (-1 << (i+1));
    int b = ~(-1 << j);
    int mask = a | b;
    
    n = n & mask;

    cout << "updated number: " << n << endl;
}

int main(){
    int n = 15; //000...001111
    // i -> 2nd bit
    // j -> 1st bit
    // clear from 1st to 2nd bit -> 000...001001 -> 9
    clearBitsInRAnge(n,2,1);
    return 0;
}