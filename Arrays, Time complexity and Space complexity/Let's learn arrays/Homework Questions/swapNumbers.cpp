#include<iostream>
using namespace std;
//different methods of swap

int main(){
    //1. swap inbuilt function
    int a=5, b=6;
    swap(a,b);
    cout<<"a: "<<a<<" "<<"b: "<<b<<endl;
    //2. temp variable
    int c=6, d=5;
    int temp=c;
    c=d;
    d=temp;
    cout<<"c: "<<c<<" "<<"d: "<<d<<endl;
    //3. arithmetic method
    int e=10, f=15;
    e=e+f; //sum of e and f stored in e
    f=e-f; //subtracting f from new e gives initial value of e
    e=e-f; //subtract new f from new e gives initial value of f
    cout<<"e: "<<e<<" "<<"f: "<<f<<endl;
    //4. XOR bitwise method
    int x=15, y=10;
    x=x^y;
    y=y^x;
    x=x^y;
    cout<<"x: "<<x<<" "<<"y: "<<y<<endl;
    return 0;
}
