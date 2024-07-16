#include<iostream>
#include<vector>
#include<forward_list>
using namespace std;
//forward iterator
int main() {
    forward_list<int> list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    //traverse
    forward_list<int>::iterator it = list.begin();
    while(it!= list.end()){
        cout<< *it <<" ";
        (*it) = (*it) + 5;
        it++;
    }
    cout<<endl;
    it = list.begin();
    while(it!= list.end()){
        cout<< *it <<" ";
        it++;
    }
    return 0;
}
