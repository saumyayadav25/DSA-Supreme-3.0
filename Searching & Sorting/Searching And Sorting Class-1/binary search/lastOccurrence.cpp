#include<iostream>
#include<algorithm>
using namespace std;
//find last occurrence
void findLastOccurrence( int arr[], int n, int target, int &ansIndex){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(arr[mid]==target){
            //may or may not be last occurrence
            //store and compute
            ansIndex= mid;
            //we want to find last occurrence
            s=mid+1;
        }
        if( target>arr[mid]){
            s=mid+1;
        }
        if(target<arr[mid]){
            e=mid-1;
        }
        //don't forget this
        mid=s+(e-s)/2;
    }
}

int main(){
    int arr[]={10,20,20,20,20,20,20,30,40,50,60};
    int n=11;
    int target=20;
    int ansIndex=-1; //-1 means target not found
    findLastOccurrence(arr,n,target,ansIndex);
    cout<<"last occurrence index: "<< ansIndex<<endl;
    return 0;
}
