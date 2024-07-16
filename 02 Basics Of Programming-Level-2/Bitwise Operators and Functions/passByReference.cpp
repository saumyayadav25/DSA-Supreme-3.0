#include<iostream>
using namespace std;
//pass by reference
void solve(int &a){
    a=a+10;
    return;
}
int main(){
    int a=10;
    a++;
    solve(a);
    a++;
    cout<<a;
    return 0;
}
