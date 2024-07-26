#include<iostream>
using namespace std;
void square(int*p){
    int a=10;  
    p=&a; //p points to local a
    *p=(*p) * (*p);
}
int main(){
    int a =10;
    square(&a);
    cout<<a; 
    return 0;
}
