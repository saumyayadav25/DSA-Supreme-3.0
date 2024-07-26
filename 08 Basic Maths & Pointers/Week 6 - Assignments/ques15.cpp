#include<iostream>
using namespace std;

int main(){
    float arr[5]={12.5, 10.0, 13.5, 90.5, 0.5};
    float *p1 = &arr[0];   //assume 200
    float *p2 = p1+3;
    cout<<*p1<<" ";
    cout<<p2-p1;   //212-200->  12/4 = 3
    return 0;
}
