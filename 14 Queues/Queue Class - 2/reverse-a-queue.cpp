#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// using stack
void reverseQueue(queue<int>& q){
    stack<int>st;
    while(!q.empty()){
        int element = q.front();
        q.pop();

        st.push(element);
    }
    // ab tak sare queue ke element stack k andar push hogye honge
    while(!st.empty()){
        int element = st.top();
        st.pop();

        q.push(element);
    }
}

// using recursion
void reverseQueueRec(queue<int>&q){
    // base case
    if(q.empty()) return;
    // 1case
    int frontElement = q.front();
    q.pop();
    // baaki recursion
    reverseQueueRec(q);
    // backtracking
    q.push(frontElement);
}

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueue(q);
    reverseQueueRec(q);

    // printing all elements
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}