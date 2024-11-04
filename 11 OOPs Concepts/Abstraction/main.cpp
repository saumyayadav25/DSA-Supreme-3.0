#include <iostream>
#include "bird.h"
using namespace std;

void birdDoesSomething(Bird *&bird){
    bird->eat();
    bird->fly();
}

int main(){
    // Bird *bird = new Sparrow();
    Bird *bird = new Eagle();
    // Bird *bird = new Pigeion();
    birdDoesSomething(bird);
    // interface same h but functionality alag ho skti h ya changes ho skte h humme code mai koi change nhi krna
    Bird *b2 = new Bird(); // cannot make object of abstract class/cpp interface
    return 0;
}



// g++ -o is used to make exe from .os
// g++ -c is used to make .os, from .cpp