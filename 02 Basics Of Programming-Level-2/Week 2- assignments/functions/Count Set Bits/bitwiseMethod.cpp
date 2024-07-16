#include<iostream>
using namespace std;
//given an integer N, count number of set bits in it.
//BITWISE METHOD
int countSetBit(int n){
    int count=0;
    while(n){
        int bit = (n & 1);
        if(bit){
            count++;
        }
        n=n>>1;
    }
    return count;
}
int main(){
    int n=5;
    int setBitCount = countSetBit(n);
    cout<<setBitCount<<endl;
    return 0;
}
