#include<iostream>
#include<stack>
using namespace std;

void solve(int arr[], int n, vector<int>&ans){
    stack<int>s;
    s.push(-1);
    for(int i=n-1;i>=0; i--){
        int element = arr[i];
        while(s.top() > element) s.pop();
        // reached here -> stack top par smaller element hai -> store ans
        ans.push_back(s.top());
        // push element to the stack
        s.push(element);
    }
}
int main(){
    // input
    int arr[] = {8,4,6,2,3};
    int n = 5;
    vector<int>ans;
    solve(arr,n,ans);
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
        cout<< i <<" ";
    }
    return 0;
}