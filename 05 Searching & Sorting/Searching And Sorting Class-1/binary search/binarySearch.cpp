// leetcode 704. Binary Search

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        while(s<=e){
            if(arr[mid]==target){
                return mid;
            }
            if(target>arr[mid]){
                s=mid+1;
            }
            else if(target<arr[mid]){
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return -1;
    }
};
