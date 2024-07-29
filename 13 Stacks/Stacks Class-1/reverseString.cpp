#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char>s;
    string name = "saumya";

    // insertion of characters into the stack
    for(int i=0; i<name.length();i++){
        char ch = name[i];
        s.push(ch);
    }

    // retrieval of characters from the stack
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}