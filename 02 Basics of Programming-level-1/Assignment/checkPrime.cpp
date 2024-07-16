#include<iostream>
using namespace std;
//prime number
bool checkPrime(int N){
    if(N<=1){
        return false;
    }
    //check if N is divisible by any number btw [2,N-1]
    for(int i=2;i<N;i++){
        if((N&i)==0){
            return false;
        }
    }
    return true;
}
int main(){
    cout << "enter n:" << endl;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        bool isPrime = checkPrime(i);
        if(isPrime){
            cout << "Prime: "<< i << endl;
        }
        else{
            cout << "non prime: "<< i << endl;
        }
    }
    return 0;
}
