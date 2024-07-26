#include<iostream>
using namespace std;

int main(){
    int ***r, **q, *p,i=8;
    p = &i;
    (*p)++;    //8+1=9
    q=&p;
    (**q)++;   //9+1=10
    r=&q;
    cout<<*p<<" "<<**q<<" "<<***r;
    return 0;
}
