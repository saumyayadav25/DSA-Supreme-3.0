#include<iostream>
#include<queue>
using namespace std;

int main(){
    //creation
    deque<int> dq;

    //insertion
    //push_back()
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    //push_front()
    dq.push_front(100);
    dq.push_front(200);

    //clear()
    //dq.clear();

    //insert()
    dq.insert(dq.begin(), 101);

    //erase()
    dq.erase(dq.begin());

    //pop()
    dq.pop_front();
    dq.pop_back();

    //size()
    cout<<"size: "<<dq.size()<<endl;

    //front()
    cout<<dq.front()<<endl;

    //back()
    cout<<dq.back()<<endl;

    //empty()
    if(dq.empty() == true){
        cout<<"deque is empty"<<endl;
    }
    else{
        cout<<"deque is not empty"<<endl;
    }

    //iterate
    deque<int>::iterator it= dq.begin();
    while(it!= dq.end()){
        cout<< *it << " ";
        it++;
    }
    cout<<endl;

    //operator[]
    cout<<dq[0]<<endl;

    //at()
    cout<<dq.at(3)<<endl;

    return 0;
}
