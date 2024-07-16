#include<iostream>
using namespace std;
//sort 0's and 1's
void sortZeroOne(int arr[], int n){
    int zeroCount=0;
    int oneCount=0;
    //counting
    for(int i=0; i<n;i++){
        if(arr[i]==0){
            zeroCount++;
        }
        if(arr[i]==1){
            oneCount++;
        }
    }
    //insertion
    //method-1
    int i=0;
    for(;i<zeroCount;i++){
        arr[i]=0;
    }
    for(i=zeroCount;i<n;i++){
        arr[i]=1;
    }
    //method-2
    // fill(arr,arr+ zeroCount,0);
    // fill(arr+zeroCount,arr+n,1);
}
int main(){
    int arr[]={0,1,1,1,0,0,1,1};
    int size=8;
    sortZeroOne(arr,size);
    
    //using sort inbuilt function
    // sort(arr,arr+size);
    
    //printing the array
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
