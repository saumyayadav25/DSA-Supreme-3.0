#include<iostream>
using namespace std;

// class abc{
// public:
//     int x, y;
//     void print() const{
//         // cout << x << " " << y << endl;
//         cout << this->x << " " << this->y << endl; //means same as above line
//     }
// };

class abc{
public:
    static int x, y;

    static void print(){ // no this pointer is accessible
        printf("I am in static %s\n", __FUNCTION__);
        cout << x << " " << y << endl;
    }
};

int abc::x;
int abc::y;

int main(){
    abc obj1;
    obj1.x = 1;
    abc::x = 1;
    // obj1.y = 2;
    abc::y = 2;
    // obj1.print();
    abc::print();
    abc obj2;
    // obj2.x = 10;
    abc::x = 10;
    // obj2.y = 20;
    abc::y = 20;

    // obj1.print();
    // obj2.print();
    abc::print();
    return 0;
}