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

bool checkPowerOfTwo(int n){
    int count = countSetBits(n);
    return count == 1 ? true : false;
}

int main(){
    int n = 16; 
    int ans = checkPowerOfTwo(n);
    if(ans == true) cout << "YES, it is power of 2" << endl;
    else cout << "NO, it is not power of 2" << endl;
    return 0; 
}