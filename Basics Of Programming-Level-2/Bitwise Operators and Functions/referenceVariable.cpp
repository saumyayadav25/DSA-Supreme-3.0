#include<iostream>
using namespace std;
//reference variable
int main(){
    int age=15;
    int &demo=age;
    age++;
    demo=demo+10;
    cout<<demo;
    return 0;
}
