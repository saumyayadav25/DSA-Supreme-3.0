#include<iostream>
using namespace std;
void increment(int **p){
    //p pointer points to ptr
    (**p)++;   //10+1=11
}
int main(){
    int num = 10;
    int *ptr = &num;
    increment(&ptr);
    cout<<num;
    return 0;
}