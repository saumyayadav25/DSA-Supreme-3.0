#include<iostream>
using namespace std;
//call stack
void hello(){
    cout<<4;
    return;
}
void solve(){
    cout<<3;
    hello();
    cout<<4;
}
int main(){
    
    cout<<1;
    solve();
    cout<<2;
    return 0;
}
