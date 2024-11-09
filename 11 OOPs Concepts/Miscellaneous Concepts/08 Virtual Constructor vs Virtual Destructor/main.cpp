#include<iostream>
using namespace std;
// ctor cannot be virtual, dtor can be

class Base{
    public:
    Base(){
        cout << "Base ctor\n";
    }

    virtual ~Base(){
        cout << "Base dtor\n";
    }
};

class Derived : public Base{
    int *a;
    public:
    Derived(){
        a = new int[1000];
        cout << "Derived ctor\n";
    }

    ~Derived(){
        delete[] a;
        cout << "Derived dtor\n";
    }
};

int main(){
    Base *b = new Derived();
    delete b;
    return 0;
}