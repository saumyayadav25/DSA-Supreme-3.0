#include<iostream>
using namespace std;
//given an integer N, count number of set bits in it.
int countSetBit(int n){
    int count =0;
    while(n>0){
        int bit=n%2;
        if(bit==1){
            count++;
        }
        n=n/2;
    }
    return count;
}
int main(){
    int n=7;
    int setBitCount = countSetBit(n);
    cout<<setBitCount<<endl;
    return 0;
}
