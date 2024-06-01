#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Comparator{
    public:
        bool operator()(int a, int b){
            return a>b;
        }
};
int main() {

    vector<int> arr;
    arr.push_back(20);
    arr.push_back(10);
    arr.push_back(15);
    sort(arr.begin(),arr.end(), Comparator());
    for(int a:arr){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
