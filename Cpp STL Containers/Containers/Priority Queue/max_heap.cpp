#include<iostream>
#include<queue>
using namespace std;

int main(){
    //creation
    priority_queue<int> pq;
    //max-heap -> highest priority ->maximum value

    //insertion
    pq.push(10);
    pq.push(25);
    pq.push(55);
    pq.push(21);

    //top() -> highest priority element
    cout<<pq.top()<<endl;

    //pop() -> pop highest priority element
    pq.pop();
    
    //size()
    cout<<pq.size()<<endl;

    if(pq.empty()==true){
        cout<<"pq is empty";
    }
    else{
        cout<<"pq is not empty"<<endl;
    }
    
    return 0;
}
