#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int>arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    //traverse using iterator
    vector<int>::iterator it =arr.begin();
    while(it!= arr.end()){
        cout << *it << " ";
        it++;
    }

    return 0;
}
