#include<iostream>
using namespace std;

int main(){
    // CONST WITH VARIABLES
    const int x = 5; // x is constant-> can't reassign value
    cout << x << endl;
    // x = 10; // gives error

    // CONST WITH POINTERS
    const int *a = new int(20); //const data, non-const pointer
    int const *c = new int(20); //means same as above line
    // *a = 2; // gives error -> can't change the content of pointer
    cout << *a << endl;
    delete a; // to avoid memory leak
    int b = 2;
    a = &b; // pointer can be reassigned
    cout << *a << endl;

    // CONST POINTER BUT NON-CONSTANT DATA
    int *const p = new int(1);
    cout << *p <<endl;
    *p = 10;
    cout << *p <<endl;
    int q = 50;
    // p = &q; -> gives error

    // BOTH POINTER AND DATA CONST
    const int *const m = new int(30);
    cout << *m << endl;
    // *m = 50; -> gives error
    int n = 300;
    // m = &n; -> gives error
    return 0;
}