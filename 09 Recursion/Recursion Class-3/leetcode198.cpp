// leetcode 198: House Robber
//Time Limit Exceeded- optimised solution will be done while doing DP
class Solution {
public:
    int solve(vector<int>&nums, int n, int i){
        //base case
        if(i>=n) return 0;
        //include
        int includeAns = nums[i] + solve(nums,n,i+2);
        //exclude
        int excludeAns = 0 + solve(nums,n,i+1);
        return max(includeAns, excludeAns);
    }
    int rob(vector<int>& nums) {
        int index = 0;
        int ans = solve(nums, nums.size(), index);
        return ans;
    }
};