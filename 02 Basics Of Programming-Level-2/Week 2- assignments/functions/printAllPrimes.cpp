#include<iostream>
using namespace std;
//function to print all prime numbers from 1 to N
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
    int n=50;
    for(int i=2;i<=n;i++){
        bool isiPrime = checkPrime(i);
        if(isiPrime){
            cout<<i<<" ";
        }
    }
    return 0;
}
