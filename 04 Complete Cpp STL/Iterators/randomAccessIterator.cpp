#include<iostream>
#include<vector>
using namespace std;
// random access Iterator
int main() {
    vector<int>arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);
    vector<int>::iterator it = arr.begin();
    while(it!= arr.end()){
        //write
        *it = *it +7;
        //read
        cout<< * it << " ";
        //forward moving
        it++;
    }
    cout<<endl;
    //backward movement
    vector<int>::iterator itb = arr.end();
    while(itb!= arr.begin()){
        //first go backward
        itb--;
        cout<< * itb << " ";
        
    }
    cout<<endl;
    //random access iterator
    vector<int>::iterator itr = arr.begin() + 3;
    cout<< *itr <<endl;
    return 0;
}
