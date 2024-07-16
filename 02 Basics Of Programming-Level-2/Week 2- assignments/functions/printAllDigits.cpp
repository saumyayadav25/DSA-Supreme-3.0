#include<iostream>
using namespace std;
//print all digits of an integer
//below function print digits in reverse order
void printAllDigits(int n){
    while(n){
        int onesPlace=n%10;
        cout<<"digit: "<< onesPlace<<endl;
        n=n/10;
    }
}
int main(){
    int n=1234;
    printAllDigits(n);
    return 0;
}
