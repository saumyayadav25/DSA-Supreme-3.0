#include<iostream>
using namespace std;

// left shift i times

void setIthBit(int n, int i){
    int mask = (1 << i);
    n = n | mask;
    cout << "Updated number: " << n << endl;
}

int main(){
    int n = 5; // 101
    setIthBit(5,1); //111 -> 7
    return 0;
}