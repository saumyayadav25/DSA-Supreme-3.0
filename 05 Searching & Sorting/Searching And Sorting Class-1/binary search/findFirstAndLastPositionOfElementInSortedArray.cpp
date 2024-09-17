// leetcode 34: Find First and Last Position of Element in Sorted Array


class Solution {
public:
    //find first occurence
void findFirstOccurence( vector<int>arr, int n, int target, int &ansIndex){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            //may or may not be first occurence
            //store and compute
            ansIndex= mid;
            //we want to find first occurence
            e=mid-1;
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
    //find last occurrence
void findLastOccurrence( vector<int> arr, int n, int target, int &ansIndex){
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
    vector<int> searchRange(vector<int>& arr, int target) {
        int n=arr.size();
        int firstOccIndex=-1;
        findFirstOccurence(arr,n,target, firstOccIndex);

        int lastOccIndex=-1;
        findLastOccurrence(arr,n,target, lastOccIndex);

        vector<int> temp(2);
        temp[0]= firstOccIndex;
        temp[1]=lastOccIndex;
        return temp;
    }
};
