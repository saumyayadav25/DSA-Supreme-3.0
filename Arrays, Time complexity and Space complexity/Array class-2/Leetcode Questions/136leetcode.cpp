#include<iostream>
using namespace std;
//136 leetcode problem
int findUniqueNumber(int arr[], int n){
    int ans=0;
    // to find the final answer, we need to XOR all the numbers in the array
    for(int i=0; i<n;i++){
        ans=ans^arr[i];
    }
    return ans;
}
int main(){
    int arr[]={2,4,1,4,1};
    int size=5;
    int ans= findUniqueNumber(arr,size);
    cout<<"Unique Number is: "<< ans << endl;
    return 0;
}
