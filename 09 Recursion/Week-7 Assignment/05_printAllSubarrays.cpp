#include<iostream>
#include<vector>
using namespace std;

void printSubArray_util(vector<int>&nums, int start, int end){
    // base
    if (end == nums.size()) return;
    // 1case
    for(int i = start; i<=end;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    // recursive call
    printSubArray_util(nums,start,end+1);
}

void printSubArray(vector<int>&nums){
    for(int start = 0; start < nums.size(); start++){
        int end = start;
        printSubArray_util(nums,start,end);
    }
}
int main(){
    vector<int>nums{1,2,3,4,5};
    printSubArray(nums);
    return 0;
}