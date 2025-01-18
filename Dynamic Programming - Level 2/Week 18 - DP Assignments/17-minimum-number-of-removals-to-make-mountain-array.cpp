// leetcode 1671. Minimum Number of Removals to Make Mountain Array

class Solution {
public:
    // TC: O(NlogN)
    // binary search to find LIS: most optimal
    int lengthOfLIS(vector<int>& nums, vector<int>&lis) {
        vector<int>ans;
        ans.push_back(nums[0]);
        lis.push_back(1);
        for(int i = 1; i<nums.size();i++){ // O(N)
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
                lis.push_back(ans.size());
            }
            else{
                // find the index of just >= the ith element(lowerbound->gives iterator not index) 
                auto it = lower_bound(ans.begin(),ans.end(),nums[i]); //O(logn)
                int index = it - ans.begin(); //get index from iterator
                ans[index] = nums[i];
                lis.push_back(index + 1);
            }
        }
        return ans.size();
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>lis, lds;
        // make lis and ldr array by taking each element as pivot
        lengthOfLIS(nums, lis);
        reverse(nums.begin(), nums.end()); // to find lds
        lengthOfLIS(nums, lds);
        // main logic
        int largestMountainLength = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(lis[i] == 1 || lds[nums.size() - i - 1] == 1) continue;
            largestMountainLength = max(largestMountainLength, lis[i] + lds[nums.size() - i - 1] - 1);
        }
        int minRemovals = nums.size() - largestMountainLength;
        return minRemovals;
    }
};