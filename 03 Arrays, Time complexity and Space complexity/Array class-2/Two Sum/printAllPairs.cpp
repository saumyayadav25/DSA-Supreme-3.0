#include<iostream>
using namespace std;
//two sum
//print all pairs if pair that sums equal to target exists
void checkTwoSumPrintAllPairs(int arr[], int n, int target){
    //check all pairs
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(arr[i]+arr[j]==target){
                //found a pair that sums to target
                cout<<arr[i]<<", "<<arr[j]<<endl;
            }
        }
    }
    //target not found in any pair
    return ;
}
int main(){
    int arr[]={10,20,30,40};
    int size=4;
    int target=60;
    checkTwoSumPrintAllPairs(arr,size,target);
    return 0;
} 
