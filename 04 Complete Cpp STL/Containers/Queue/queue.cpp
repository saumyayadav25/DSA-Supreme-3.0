#include<iostream>
#include<queue>
using namespace std;

int main(){
    //creation
    queue<int> q;
    queue<int> r;

    //insertion
    //push()
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    r.push(100);
    r.push(200);
    //size()
    cout<<"size: "<<q.size()<<endl;

    //pop()
    q.pop();

    //epmty()
    if(q.empty()==true){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }

    //front()
    cout<<q.front()<<endl;

    //back()
    cout<<q.back()<<endl;

    //swap
    q.swap(r);
    cout<<q.front()<<" "<< r.front() << endl;
    return 0;
}
