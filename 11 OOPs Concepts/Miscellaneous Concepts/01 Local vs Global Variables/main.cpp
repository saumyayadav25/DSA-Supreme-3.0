#include<iostream>
using namespace std;

int x = 2; // global variable

void fun(){
    int x = 60;
    cout << x << endl;
    ::x = 40; //another way to access global variable
    cout << ::x << endl;
}



int main(){
    cout << x << endl;

    x = 20; // access global variable
    cout << x << endl;

    int x = 200; //local to main() fxn
    cout << x << endl;

    cout << ::x <<endl; // accessing GLOBAL WITH ::

    {
        int x = 1000;
        cout << x << endl;
        cout << ::x << endl;
    }

    fun();
    return 0;
}

// most local variable is accessed