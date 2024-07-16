//leetcode 33: search in rotated sorted array
class Solution {
public:
    int getPivotIndex(vector<int>& arr) {
        int s = 0;
        int n = arr.size();
        int e = n-1;
        int mid = s+(e-s)/2;

        while(s <= e) {
            if(s == e) {
                return s;
            }
            if(mid+1 < n && arr[mid] > arr[mid+1]) {
                return mid;
            }
            if(arr[s] > arr[mid] ) {
                e = mid-1;
            }
            else {
                //right
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }
    int binarySearch(int s, int e, int target, vector<int> arr) {
        int mid = s+(e-s)/2;
        while(s<=e) {
            if(arr[mid] == target) {
                return mid;
            }
            if(target > arr[mid]) {
                s = mid+1;
            }
            else {
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //Step1
        int pivotIndex = getPivotIndex(nums);

        //lineA
        //start -> 0 index
        //end -> pivotIndex

        //line B
        //start -> pivotIndex+1;
        //end -> n-1;
        int n = nums.size();
        if(target >= nums[0] && target <= nums[pivotIndex]) {
            int ans = binarySearch(0, pivotIndex, target, nums);
            return ans;
        }
        else {
            int ans = binarySearch(pivotIndex+1, n-1, target, nums);
            return ans;
        }
        return -1;
    
    }
};
