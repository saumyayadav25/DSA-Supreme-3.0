#include<iostream>
using namespace std;
//odd occuring element
//All element occurs even number of times except one; Element repeats itself in pairs; No pair repeats itself, no number can occur more than 2 times in a single stretch; Find element that occur odd times

int findOddOccuringElement(int arr[], int size){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        //single element
        if(s==e){
            return s;
        }
        //duplicate does'nt exist
        if(mid-1>=0 && arr[mid] != arr[mid-1] && mid+1<size && arr[mid]!=arr[mid+1]){ //index should be valid,i.e. mid-1>0 && mid+1<size
            return mid;
        }
        //duplicate exist in left index
        if(mid-1>=0 && arr[mid]==arr[mid-1]){
            int pairStartingIndex=mid-1;
            if(pairStartingIndex & 1){
                //pairStartingIndex is odd
                //move left
                e=mid-1;
            }
            else{
                //pairStartingIndex is even
                //move right
                s=mid+1;
            }
        }
        //duplicate exist in right index
        else if(mid+1<size && arr[mid]==arr[mid+1]){
            int pairStartingIndex= mid;
            if(pairStartingIndex & 1){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        mid=s+(e-s)/2;
    }
    return -1;
}
int main(){
    int arr[] = {1,1,2,2,3,3,4,5,5,6,6};
    int size=11;

    int ans=findOddOccuringElement(arr,size);
    cout<<"ans Index : "<<ans<<endl;
    cout<<"ans element : "<<arr[ans]<<endl;
    return 0;
}
