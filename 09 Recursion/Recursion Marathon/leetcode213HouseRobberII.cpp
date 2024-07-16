// leetcode 213: House Robber II
class Solution {
public:
int solve(vector<int>&nums, int s, int e){
        //base case
        if(s>e) return 0;
        //include
        int includeAns = nums[s] + solve(nums,s+2,e);
        //exclude
        int excludeAns = 0 + solve(nums,s+1,e);
        return max(includeAns, excludeAns);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //single element
        if(n==1) return nums[0];
        
        int includeAns = solve(nums, 0, n-2);
        int excludeAns = solve(nums, 1, n-1);
        int ans = max(includeAns, excludeAns);
        return ans;
    }
};