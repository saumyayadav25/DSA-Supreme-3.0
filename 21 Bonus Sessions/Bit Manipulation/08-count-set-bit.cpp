#include<iostream>
using namespace std;

int countSetBits(int n){
    int count = 0;
    while(n != 0){
        count++;
        n = n & (n-1);
    }
    return count;
}

int main(){
    int n = 15; // 1111
    cout << countSetBits(n) << endl;
    return 0; 
}