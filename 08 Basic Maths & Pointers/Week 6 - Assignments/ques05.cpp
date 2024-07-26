#include<iostream>
using namespace std;

int main(){
    int a = 7;    //suppose address of a to be 300
    int *c = &a;
    c = c+1;   // now c pointer points to address 304->random location
    cout<<a<<" "<<*c;
    return 0;
}
