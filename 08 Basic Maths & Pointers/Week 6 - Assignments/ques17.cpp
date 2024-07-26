#include<iostream>
using namespace std;
void fun(int a[]){
    cout<<a[0]<<" ";
}
int main(){
    int a[]={1,2,3,4};
    fun(a+1);
    cout<<a[0];
    return 0;
}
