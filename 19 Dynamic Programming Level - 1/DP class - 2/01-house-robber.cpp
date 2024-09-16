// leetcode 198. House Robber

class Solution {
public:
    int solve(vector<int>&nums,int i){
        // base case
        if(i >= nums.size()){
            return 0;
        }
        // 1 case
        // include-exclude 
        int include = nums[i] + solve(nums,i+2);
        int exclude = 0 + solve(nums,i+1);
        int finalAns = max(include,exclude);
        return finalAns;
    }
    // 1D dp
    // top-down: rec + mem: tc/sc: O(N)
    int solveMem(vector<int>&nums,int i, vector<int>&dp){
        // base case
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        // 1 case
        // include-exclude 
        int include = nums[i] + solveMem(nums,i+2,dp);
        int exclude = 0 + solveMem(nums,i+1,dp);
        dp[i] = max(include,exclude);
        return dp[i];
    }
    
    // bottom-up: iterative: tc/sc: O(N)
    int solveTab(vector<int>&nums){
        int n = nums.size();
        vector<int> dp(n+2,0);
        // dp[n] = 0;
        // dp[n+1] = 0;

        for(int i = n - 1; i >= 0; i--){
            int include = nums[i] + dp[i+2];
            int exclude = 0 + dp[i+1];
            dp[i] = max(include,exclude);
        }

        return dp[0];
    }
    
    // space-optimisation: sc:O(1)
    int solveSpaceOpt(vector<int>&nums){
        int n = nums.size();
        int next1 = 0;
        int next2 = 0;

        for(int i = n - 1; i >= 0; i--){
            int include = nums[i] + next2;
            int exclude = 0 + next1;
            int curr = max(include,exclude);
            // shifting krna bhool gaye
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
    
    int rob(vector<int>& nums) {
        // return solve(nums,0);


        // int n = nums.size();
        // vector<int> dp(n+1,-1);
        // int i = 0;
        // return solveMem(nums,i,dp);


        int n = nums.size();
        // return solveTab(nums);


        return solveSpaceOpt(nums);
    }
};