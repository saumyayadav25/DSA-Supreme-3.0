#include<iostream>
using namespace std;
//function to check whether given number is prime or not
bool checkPrime(int n){
    int i=2;
    for(i=2;i<n;i++){
        if((n%i)==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n=5;
    bool isPrime = checkPrime(n);
    if(isPrime){
        cout<<"prime\n";
    }
    else{
        cout<<"not prime\n";
    }
    return 0;
}
