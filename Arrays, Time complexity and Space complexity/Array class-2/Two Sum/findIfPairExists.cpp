#include<iostream>
using namespace std;
//two sum
//check if a pair that sums equal to target exists or not
bool checkTwoSum(int arr[], int n, int target){
    //check all pairs
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(arr[i]+arr[j]==target){
                //found a pair that sums to target
                return true;
            }
        }
    }
    //target not found in any pair
    return false;
}
int main(){
    int arr[]={10,20,30,40};
    int size=4;
    bool ans= checkTwoSum(arr,size,60);
    if(ans==true){
        cout<<"pair found"<<endl;
    } 
    else{
        cout<<"pair not found"<<endl;
    }
    return 0;
} 
