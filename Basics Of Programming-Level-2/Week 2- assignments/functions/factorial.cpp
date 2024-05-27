#include<iostream>
using namespace std;
//function to find factorial of a number
int fact( int n){
    int fact=1;
    for(int i=1; i<=n; i++){
        fact=fact*i;
    }
    return fact;
}

int main(){
    int n=10;
    int ans = fact(n);
    cout<<"factorial: "<< ans <<endl;
    return 0;
}
