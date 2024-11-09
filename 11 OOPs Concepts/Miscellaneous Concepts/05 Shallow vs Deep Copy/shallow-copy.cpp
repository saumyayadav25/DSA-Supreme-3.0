#include<iostream>
using namespace std;

class abc{
    public:
    int x;
    int *y;

    abc(int _x, int _y): x(_x), y(new int(_y)) {}

    // default dumb copy ctor: does SHALLOW copy
    abc(const abc &obj){
        x = obj.x;
        y = obj.y;
    }

    void print() const{
        printf("X: %d\nPTR Y: %p\nContent of Y (*y): %d\n\n", x, y,*y);
    }

    // ~abc(){
    //     delete y;
    // }
};

int main(){
    abc a(1,2);
    a.print();

    // abc b(a); // means same as below line
    abc b = a;  //copy ctor is called by default
    b.print();
    *b.y = 20;
    b.print();
    a.print();


    // problem with shallow copy in dtor
    // abc*a = new abc(1,2);
    // abc b = *a;
    // delete a; // y is deleted.
    // b.print(); 
    // return 0; // while returning since b is in heap memory, it will try to delete b but it's content is already deleted as y of bis pointing to y of a -> gives error
}