// leetcode 300. Longest Increasing Subsequence
// ->other approach done in live class

// optimised solution : BINARY SEARCH
// TC: O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);

        for(int i = 1; i<nums.size();i++){ // O(N)
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                // find the index of just >= the ith element(lowerbound->gives iterator not index) 
                auto it = lower_bound(ans.begin(),ans.end(),nums[i]); //O(logn)
                int index = it - ans.begin(); //get index from iterator
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
};