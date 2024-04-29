#include<iostream>
#include<cmath>
using namespace std;
//method 1
int decimalToBinary1(int n){
    //division method
    int binaryno=0;
    int i=0;
    while(n>0){
        int bit=n%2;
        // cout<<bit;
        binaryno=bit*pow(10,i++)+binaryno;
        n=n/2;
    }
    return binaryno;
}
//method 2
int decimalToBinary2(int n){
    //bitwise method
    int binaryno=0;
    int i=0;
    while(n>0){
        int bit=n&1;
        binaryno=bit*pow(10,i++)+binaryno;
        n=n>>1;
    }
    return binaryno;
}
int main(){
    int n;
    cin>>n;
    // int binary=decimalToBinary1(n);
    int binary=decimalToBinary2(n);
    cout<<binary<<endl;
}
