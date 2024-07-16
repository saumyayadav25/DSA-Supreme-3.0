#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    vector<int> arr;
    arr.push_back(22);
    arr.push_back(11);
    arr.push_back(55);
    arr.push_back(66);
    arr.push_back(77);

    //make_heap
    make_heap(arr.begin(),arr.end()); 
    for(int a: arr){
        cout<<a<<" ";
    }
    cout<<endl;

    //insertion
    //push_heap
    arr.push_back(99);
    push_heap(arr.begin(),arr.end()); 
    for(int a: arr){
        cout<<a<<" ";
    }
    cout<<endl;

    //deletion
    //pop_heap
    pop_heap(arr.begin(),arr.end());
    // for(int a: arr){
    //     cout<<a<<" ";
    // }
    // cout<<endl;
    arr.pop_back();

    //sort_heap
    sort_heap(arr.begin(),arr.end());
    for(int a: arr){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
