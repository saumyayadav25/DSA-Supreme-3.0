#include<iostream>
using namespace std;

inline void showNum(int num){
    cout << num << endl;
}

int main(){
    showNum(10);
    showNum(20);
    showNum(100);
    showNum(50);
    showNum(5);
    showNum(1);
    return 0;
}