#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int>&s, int count){
    // base case
    if(count == 0){
        cout<< s.top()<<endl;
        return;
    }
    // 1case
    int topElement = s.top();
    s.pop();
    count--;
    // rec
    printMiddle(s,count);
    // backtrack
    s.push(topElement);
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int count = s.size() / 2;
    printMiddle(s, count);
    return 0;
}