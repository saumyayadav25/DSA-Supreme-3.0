#include<iostream>
#include<stack>
using namespace std;

void solve(int arr[], int n, vector<int>&ans){
    stack<int>s;
    s.push(-1);
    // loop bas n-1 se 0 ki jgh 0 se n-1 tk chalega
    for(int i=0;i<n; i++){
        int element = arr[i];
        while(s.top() > element) s.pop();
        // reached here -> stack top par smaller element hai -> store ans
        ans.push_back(s.top());
        // push element to the stack
        s.push(arr[i]);
    }
}
int main(){
    // input
    int arr[] = {8,4,6,2,3};
    int n = 5;
    vector<int>ans;
    solve(arr,n,ans);
    // reverse(ans.begin(),ans.end());
    for(auto i:ans){
        cout<< i <<" ";
    }
    return 0;
}