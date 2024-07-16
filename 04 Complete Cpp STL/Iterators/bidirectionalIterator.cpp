#include<iostream>
#include<vector>
#include<list>
using namespace std;
//bidirectional Iterator
int main() {
    list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    //traverse
    list<int>::iterator it = myList.begin();
    while( it!= myList.end()){
        //write
        (*it) = (*it) + 2;
        //read
        cout<< (*it) << " ";
        //forward moving
        it++;
    }
    cout<<endl;
    //backward moving
    list<int>::iterator itb = myList.end();
    while(itb != myList.begin()){
        itb--;
        *itb = *itb +5;
        cout<< (*itb) <<" ";
    }
    return 0;
}
