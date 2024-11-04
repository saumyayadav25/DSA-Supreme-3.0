#include <iostream>
using namespace std;

// Function Overloading -> differ in argument count/ type

class Add{
  public:
    // add int x and int y
    int sum(int x, int y){
        cout << "Sum of 2 int" << endl;
        return x + y;
    }

    // add 3 integers
    int sum(int x, int y, int z){
        cout << "Sum of 3 int" << endl;
        return x + y + z;
    }

    // add double x and double y
    double sum(double x, double y){
        cout << "Sum of 2 doubles" << endl;
        return x + y;
    }
};


int main(){
    int x = 5, y = 5;
    int z = 2;

    Add add; // object creation

    cout << add.sum(x, y) << endl;

    cout << add.sum(x, y, z) << endl;

    cout << add.sum(5.4, 2.3) << endl;
    return 0;
}
