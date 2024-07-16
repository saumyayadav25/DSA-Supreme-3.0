#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    //binary_search : O(logN)
    int target = 40;
    bool it = binary_search(arr.begin(),arr.end(),target); //return bool value
    cout<< it <<endl;

    //lower_bound
    auto it1 = lower_bound(arr.begin(), arr.end(), 35);
    cout<< *it1 << endl;

    //upper_bound
    auto it2 = upper_bound(arr.begin(), arr.end(), 40);
    cout<< *it2 <<endl;

    //equal_range: HW
    vector<int> vec = {4, 4, 5, 5, 5, 6, 7, 7, 7, 7, 7, 8, 9};
    int count = 0;
    auto range = equal_range(vec.begin(), vec.end(), 7);
    for (auto i = range.first; i!= range.second; ++i)
        ++count;
    cout << "Element 7 occurs " << count << " times." << endl;

    return 0;
}
