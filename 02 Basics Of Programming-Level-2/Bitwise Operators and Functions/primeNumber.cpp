#include<iostream>
using namespace std;
//prime number
bool isPrime(int number){
    for(int i=2;i<=(number-1);i++){
        if(number%i==0){
            //not prime
            return false;
        }
    }
    return true;
}
int main(){
    bool ans=isPrime(11);
    if(ans==true){
        cout<<"prime";
    }
    else{
        cout<<"not prime";
    }
    return 0;
}
