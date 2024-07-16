#include<iostream>
using namespace std;

int main(){
    //assignment
    int a=10;
    int b=5;
    //arithmetic
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a*b<<endl;
    cout<<a/b<<endl;
    cout<<a%b<<endl;
    //relational
    cout<<(a>b)<<endl;
    cout<<(a<b)<<endl;
    cout<<(a>=b)<<endl;
    cout<<(a<=b)<<endl;
    cout<<(a==b)<<endl;
    cout<<(a!=b)<<endl;
    //shorthand
    a+=10;
    cout<<a<<endl;
    //logical
    int cond1= (10>5);
    int cond2=(20>14);
    int cond3=(30<25);
    cout<<(cond1 && cond2 && cond3)<<endl;
    cout<<(cond1 && cond2 || cond3)<<endl;
    cout<<(cond1 && cond2 && !(cond3))<<endl;
    //unary
    cout<<(++a)*(--b)<<endl;
    cout<<(a++)*(--b)<<endl;
    cout<<(a++)*(b--)<<endl;
    return 0;
}
