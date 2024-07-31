#include<iostream>
#include<stack>
using namespace std;

bool checkSorted(stack<int>&s, int element1){
    // base case
    if(s.empty()){
        // stack poora compare ho chuka hai poora sorted hai
        return true;
    }
    // 1case
    int element2 = s.top();
    s.pop();
    if(element2 < element1){
        bool aageKaAns = checkSorted(s, element2);
        return aageKaAns;
    }
    else{
        // not sorted, no need to check further
        return false;
    }
}

int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int element1 = INT_MAX;
    cout << checkSorted(s,element1)<<endl;
    return 0;
}