#include<iostream>
using namespace std;
//iterative-loop
int binarySearch(int arr[], int size, int target){
    int s=0;
    int e=size-1;
    int mid=(s+e)/2;
    while(s<=e){
        if(arr[mid]==target) return mid;
        if(target>arr[mid]) s=mid+1;
        else e=mid-1;
        mid=(s+e)/2;
    }
    return -1;
}

//recursive
int binarySearchRecursive(int arr[], int n, int s, int e, int target){
    //base case
    if(s>e) return -1;
    int mid = (s+e)/2;
    //recursive relation
    if(arr[mid]==target) return mid;
    if(target > arr[mid]) {
        //right ki recursive call
        // s=mid+1;
        return binarySearchRecursive(arr,n,mid+1,e,target);
    }
    else{
        //left
        // e=mid-1;
        return binarySearchRecursive(arr,n,s,mid-1,target);
    }
}

int main(){
    int arr[]={10,20,30,40,50,60,70};
    int size=7;
    int target=50;

    int ans = binarySearch(arr,size,target);
    cout<<ans<<endl;

    int s=0;
    int e=size-1;
    int recAns = binarySearchRecursive(arr,size,s,e,target);
    cout<<recAns<<endl;
    return 0;
}