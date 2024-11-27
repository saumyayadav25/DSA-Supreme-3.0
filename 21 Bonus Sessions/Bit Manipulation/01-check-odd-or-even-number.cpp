#include<iostream>
using namespace std;

// n & 1

void checkEvenOdd(int n){
    if(n&1) cout << "Odd" << endl;
    else cout << "Even" << endl;
}
int main(){
    int n = 9;
    checkEvenOdd(n);
    return 0;
}