#include<iostream>
using namespace std;
int main(){
    cout<<"UNARY OPERATORS"<<endl;
    int a=5;
    cout<<a<<endl;
    cout<<(++a)<<endl;
    cout<<(a++)<<endl;
    cout<<a<<endl;
    cout<<(--a)<<endl;
    cout<<(a--)<<endl;
    cout<<a<<endl;

    cout<<"ARITHMETIC OPERATORS"<<endl;
    int b=10;
    int c=5;
    cout<<(b+c)<<endl;
    cout<<(b-c)<<endl;
    cout<<(b*c)<<endl;
    cout<<(b/c)<<endl;
    cout<<(b%c)<<endl; //gives remainder
    cout<<(5/2)<<endl;
    cout<<(5.0/2)<<endl;
    cout<<(5/2.0)<<endl;
    cout<<(5.0/2.0)<<endl;
    cout<<(5*1.0/2)<<endl;

    cout<<"RELATIONAL OPERATORS"<<endl;
    cout<<(10>5)<<endl;
    cout<<(10==5)<<endl;
    cout<<(10<=10)<<endl;
    cout<<(10!=5)<<endl;

    cout<<"LOGICAL OPERATORS"<<endl;
    bool cond1= true;
    bool cond2=(2==2);
    bool cond3=false;
    if (cond1 && cond2 && cond3){
        cout<<"all conditions are true"<<endl;
    }
    else if (cond1 || cond2 || cond3){
        cout<<"atleast one of the three conditions is true"<<endl;
    }
    else{
        cout<<"all condition are false"<<endl;
    }

    bool con= (5!=10);
    cout<<!con<<endl;

    cout<<"ASSIGNMENT OPERATORS"<<endl;
    int arr=5;
    cout<<arr<<endl;
    arr+=10;
    cout<<arr<<endl;

    cout<<"BITWISE OPERATORS"<<endl;
    cout<<(5&4)<<endl;
    cout<<(5|4)<<endl;
    cout<<(~1)<<endl;
    cout<<(~5)<<endl;
    cout<<(5<<1)<<endl;
    cout<<(5<<2)<<endl;
    cout<<(5<<3)<<endl;
    cout<<(1>>1)<<endl;
    cout<<(10>>1)<<endl;
    cout<<(100>>1)<<endl;
    cout<<(100>>3)<<endl;
    cout<<(5^4)<<endl;
    cout<<(5^5)<<endl;
    cout<<(5^3)<<endl;
    return 0;
}
