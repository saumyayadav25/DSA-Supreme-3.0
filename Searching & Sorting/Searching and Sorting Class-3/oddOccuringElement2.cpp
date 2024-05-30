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
        int leftValue=-1;
        int rightValue=-1;
        int currentValue =arr[mid];
        if(mid-1>=0){
            leftValue=arr[mid-1];
        }
        if(mid+1<size){
            rightValue=arr[mid+1];
        }
        if(currentValue != leftValue && currentValue!= rightValue){
            return mid;
        }
        //duplicate exist in left index
        if(mid-1>=0 && currentValue==leftValue){
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
        else if(mid+1<size && currentValue==rightValue){
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
    int arr[] = {1,1,2,2,3};
    int size=5;

    int ans=findOddOccuringElement(arr,size);
    cout<<"ans Index : "<<ans<<endl;
    cout<<"ans element : "<<arr[ans]<<endl;
    return 0;
}
