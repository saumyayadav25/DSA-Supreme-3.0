#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int a =10;
    int b=15;
    //min
    cout<< min(a,b)<<endl;
    //max
    cout<<max(a,b)<<endl;

    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);
    //min_element
    auto it=min_element(arr.begin(),arr.end());
    cout<< * it <<endl;
    //max_element
    auto it1=max_element(arr.begin(),arr.end());
    cout<< * it1 <<endl;
    return 0;
}
