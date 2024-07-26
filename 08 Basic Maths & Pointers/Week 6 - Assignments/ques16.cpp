#include<iostream>
using namespace std;
void changeSign(int *p){
    *p = (*p) * -1;
}
int main(){
    int a =10;
    changeSign(&a);
    cout<<a;
    return 0;
}
