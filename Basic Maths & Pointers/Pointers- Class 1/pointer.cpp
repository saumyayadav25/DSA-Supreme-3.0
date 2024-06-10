#include<iostream>
using namespace std;
int main(){
    int a =5;
    cout<<a<<endl;
    int b = a;
    // int c = &a; ->gives error
    int* ptr=&a;
    cout<<&a<<endl;
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;
    cout<<sizeof(ptr)<<endl;
    char ch='a';
    char*cptr=&ch;
    cout<<sizeof(cptr)<<endl;
    long l=1040;
    long*lptr=&l;
    cout<<sizeof(lptr)<<endl;

    int*p=&a;
    // copying pointers
    int*q=p;
    cout<<"a:"<<a<<endl;
    cout<<"&a:"<<&a<<endl;
    // cout<<"*a:"<<*a<<endl; ->gives error
    cout<<"p:"<<p<<endl;
    cout<<"&p:"<<&p<<endl;
    cout<<"*p:"<<*p<<endl;
    cout<<"q:"<<q<<endl;
    cout<<"&q:"<<&q<<endl;
    cout<<"*q:"<<*q<<endl;

    // pointer with arrays
    int arr[]={10,20,30,40};
    int *atr = arr;
    // arr=arr+1;

    // char arrays
    char c[100]="loveBabbar";
    cout<<"base address:" <<&c<<endl;
    char*ctr=c;
    cout<<ctr<<endl;
    cout<<"c:"<<c<<endl;
    cout<<"&c:"<<&c<<endl;
    cout<<"c[0]:"<<c[0]<<endl;
    cout<<"&ctr:"<<&ctr<<endl;
    cout<<"*c:"<<*c<<endl;
    cout<<"*(ctr+3):"<<*(ctr+3)<<endl;
    // remember this: it doesnt give 104, it prints lovebabbar
    cout<<"ctr:"<<ctr<<endl;
    cout<<"ctr+3:"<<ctr+3<<endl;

    char d='a';
    char *dtr=&d;
    cout<<dtr<<endl;

    char race[100]="racecar";
    char*rtpr=&race[0];
    cout<<"race: "<<race<<endl;
    cout<<"&race: "<<&race<<endl;
    cout<<"*(race+3): "<<*(race+3)<<endl;
    cout<<"rtpr: "<<rtpr<<endl;
    cout<<"&rtpr: "<<&rtpr<<endl;
    cout<<"*(rtpr+3): "<<*(rtpr+3)<<endl;
    cout<<"rtpr+2: "<<rtpr+2<<endl;
    cout<<"*rtpr: "<<*rtpr<<endl;
    cout<<"rtpr+4: "<<rtpr+4<<endl;
    return 0;
}