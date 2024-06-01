//leetcode 852: peak index in a mountain array
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=-1;
        int start=0;
        int end= arr.size() -1;
        while(start<=end){
            int mid = (start + end)>>1;
            if(arr[mid]< arr[mid+1]){
                //peak at right side
                start=mid+1;
            }
            else if(arr[mid] < arr[mid-1]){
                //peak at left side
                end = mid-1;
            }
            else{
                ans=mid;
                break;
            }
        }
        return ans;
    }
};
