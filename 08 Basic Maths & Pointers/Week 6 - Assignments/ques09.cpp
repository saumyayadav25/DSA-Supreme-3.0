#include<iostream>
using namespace std;

int main(){
    char b[]="xyz";
    char *c = &b[0];
    cout << c;
    // it was int array, c would have given index of first position, let's assume 200
    return 0;
}
