#include<iostream>
using namespace std;
// gives error
int main(){
    int *ptr = 0;    //null pointer
    int a = 10;
    *ptr = a;
    cout<< *ptr;
    return 0;
}
