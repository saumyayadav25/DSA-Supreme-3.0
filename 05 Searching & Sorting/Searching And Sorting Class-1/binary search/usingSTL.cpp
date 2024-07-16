#include<iostream>
#include<algorithm>
using namespace std;
//binary search: using STL
int main(){
    int arr[]={10,20,30,40,50,60,70,80,90};
    int n=9;
    int target=70;
    bool ans =binary_search(arr, arr+n,target);
    cout<< ans << endl;
    return 0;
}
