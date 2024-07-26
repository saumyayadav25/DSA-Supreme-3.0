#include<iostream>
using namespace std;
int f(int x, int *py, int **ppz){
    // x stores value 4, *py points to c, **ppz points to b
    int y,z;
    **ppz+=1;   //double dereference-> c=5
    z=**ppz;    //5
    *py+=2;     //c=7
    y=*py;      //7
    x+=3;       //4+3=7
    return x+y+z;
}
int main(){
    int c, *b, **a;
    c = 4;
    b=&c;
    a=&b;
    cout<<f(c,b,a);
    return 0;
}