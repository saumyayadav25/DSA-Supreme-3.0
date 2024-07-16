#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cout<<"IMPLICIT TYPE CASTING"<<endl;
    //int to float
    int n1=10;
    float n2=5.5;
    float result=n1+n2;
    cout<<result<<endl;
    //char to int
    char ch='A'; //ASCII value of A is 65
    int a=ch+1;
    char ac=ch+1;
    cout<<ac<<endl;
    cout<<a<<endl;
    //int to char
    int b=97;
    char c=b;
    cout<<c<<endl;

    cout<<"EXPLICIT TYPE CASTING"<<endl;
    //float to int
    float num1=10;
    float num2=5.5;
    float res=num1+(int)num2; //num2 is 5 now after converting to int
    cout<<res<<endl;
    //double to int
    double pi=3.14159265;
    int intPi=(int)pi;
    cout<<intPi<<endl;
    //float to char
    float floatingNumber=65.63;
    char charValue=(char)floatingNumber;
    cout<<charValue<<endl;
    //int to float
    int x=10;
    int y=3.0;
    float z=x/((float)y);
    cout<<z<<endl;
}
