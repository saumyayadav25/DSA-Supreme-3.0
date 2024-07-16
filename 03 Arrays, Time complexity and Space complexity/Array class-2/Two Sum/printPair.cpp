#include<iostream>
using namespace std;
//two sum
//return pair if a pair that sums equal to target exists
pair<int,int> checkTwoSum(int arr[], int n, int target){
    //assuming (-1,-1) as no answer found
    pair<int,int> ans=make_pair(-1,-1);

    //check all pairs
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(arr[i]+arr[j]==target){
                //found a pair that sums to target
                ans.first=arr[i];
                ans.second=arr[j];
                return ans;
            }
        }
    }
    //target not found in any pair
    return ans;
}
int main(){
    int arr[]={10,20,30,40};
    int size=4;
    pair<int,int> ans= checkTwoSum(arr,size,600);
    if(ans.first==-1 && ans.second==-1){
        cout<<"pair not found"<<endl;
    } 
    else{
        cout<<"pair found: "<< ans.first <<", "<< ans.second <<endl;
    }
    return 0;
} 
