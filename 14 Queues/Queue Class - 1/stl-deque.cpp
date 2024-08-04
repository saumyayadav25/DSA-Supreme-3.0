#include<iostream>
#include<queue>
using namespace std;

int main(){
    // doubly ended queue
    deque<int> dq;
    // insertion
    dq.push_front(10);
    dq.push_front(30);
    dq.push_front(50);
    dq.push_back(70);
    dq.push_back(100);
    // size
    cout<<dq.size()<<endl;
    // empty
    cout<<dq.empty()<<endl;
    // front
    cout<<dq.front()<<endl;
    // back
    cout<<dq.back()<<endl;
    // remove
    dq.pop_front();
    cout<<dq.front()<<endl;
    dq.pop_back();
    cout<<dq.back()<<endl;
    return 0;
}