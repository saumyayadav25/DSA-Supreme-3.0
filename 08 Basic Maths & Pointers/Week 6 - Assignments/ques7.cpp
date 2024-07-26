#include<iostream>
using namespace std;

int main(){
    int a[]={1,2,3,4};
    int *p = a++;  //it means int*p = (a=a+1)->gives error
    cout<<*p;
    return 0;
}
