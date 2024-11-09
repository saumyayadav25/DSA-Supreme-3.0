#include<iostream>
using namespace std;

class abc{
    public:
    int x;
    int *y;

    abc(int _x, int _y): x(_x), y(new int(_y)) {}

    // our smart DEEP copy
    abc(const abc&obj){
        x = obj.x;
        y = new int(*obj.y); // The value of y was taken from a and placed in a different memory location, and the address of that location was assigned to y of b.
    }

    void print() const{
        printf("X: %d\nPTR Y: %p\nContent of Y (*y): %d\n\n", x, y,*y);
    }

    ~abc(){
        delete y;
    }
};

int main(){
    // abc a(1,2);
    // a.print();

    // // abc b(a); // means same as below line
    // abc b = a;  //copy ctor is called by default
    // b.print();
    // *b.y = 20;
    // b.print();
    // a.print();


    // dtor in deep copy
    abc *a = new abc(1,2);
    abc b = *a;
    delete a;
    b.print(); // no error in deep copy
    return 0;
}