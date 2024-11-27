#include<iostream>
using namespace std;

// left shift i times

int getIthBit(int n, int i){
    int mask = (1 << i);
    int ans = n & mask;
    return ans == 0 ? 0 : 1;
}

int main(){
    cout << getIthBit(10,3 ) << endl;
    return 0;
}