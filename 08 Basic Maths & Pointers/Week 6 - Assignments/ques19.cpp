#include<iostream>
using namespace std;
void Q(int z){
    z+=z;            //7+7
    cout<<z<<" ";    //14
}
void P(int *y){
    int x = *y +2;   //local x   -> 5+2
    Q(x);
    *y = x-1;        //7-1 -> 6
    cout<<x<<" ";    //7
}
int main(){
    int x = 5;
    P(&x);
    cout<<x;         //6
    return 0;
}
