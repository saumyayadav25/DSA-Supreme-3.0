#include<iostream>
#include<queue>
using namespace std;

int main(){
    // by default- max heap
    // creation
    priority_queue<int> maxheap;
    
    // insertion
    maxheap.push(10);
    maxheap.push(5);
    maxheap.push(30);
    maxheap.push(15);
    // access front element
    cout<< maxheap.top()<<endl;
    // removal
    maxheap.pop();
    cout<< maxheap.top()<<endl;

    cout<<maxheap.size()<<endl;

    if(!maxheap.empty()) cout<<"not empty"<<endl;
    // min heap
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(10);
    minheap.push(5);
    minheap.push(30);
    minheap.push(20);
    cout<<minheap.top()<<endl;
    minheap.pop();
    cout<<minheap.top()<<endl;
    return 0;
}
