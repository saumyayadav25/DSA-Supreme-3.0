#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int>&s, int val){
    // base case
    if(s.empty()){  //agar stack empty ho jaye
        s.push(val);
        return;
    }
    if(!s.empty() && s.top()<val){
        s.push(val);
        return;
    }
    // 1case
    int topE = s.top();
    s.pop();
    // recursion
    sortedInsert(s,val);
    // BT
    s.push(topE);
}

void print(stack<int>&s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int val = 23;

    sortedInsert(s,val);
    print(s);
    return 0;
}