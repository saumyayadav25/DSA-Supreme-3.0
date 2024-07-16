#include<iostream>
using namespace std;
//function to display area of circle
float CircleArea(int radius){
    float area= 3.14 * radius * radius;
    return area;
}
int main(){
    float radius= 6.04;
    float area= CircleArea(radius);
    cout<<"area of circle: " << area << endl;
    return 0;
}
