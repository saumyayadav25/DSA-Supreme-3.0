// leetcode 312. Burst Balloons

class Solution {
public:
    // exponential TC
    int solve(vector<int>&nums, int start, int end){
        if(start > end) return 0;
        int coins = INT_MIN;
        for(int i = start; i <= end; i++){
            coins = max(coins, 
                        nums[start - 1]*nums[i]*nums[end + 1] 
                        + solve(nums, start, i - 1) + solve(nums,i + 1, end)
                    );
        }
        return coins;
    }

    int solveTD(vector<int>&nums, int start, int end, vector<vector<int>>&dp){
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int coins = INT_MIN;
        for(int i = start; i <= end; i++){
            coins = max(coins, 
                        nums[start - 1]*nums[i]*nums[end + 1] 
                        + solveTD(nums, start, i - 1, dp) + solveTD(nums,i + 1, end, dp)
                    );
        }
        return dp[start][end] = coins;
    }

    int solveBU(vector<int>&nums){
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), 0));
        int n = nums.size() - 2;
        for(int start = n; start >= 1; start--){
            for(int end = start; end <= n; end++){
                int coins = INT_MIN;
                for(int i = start; i <= end; i++){
                    coins = max(coins, 
                                nums[start - 1]*nums[i]*nums[end + 1] 
                                + dp[start][i - 1] + dp[i + 1][end]
                            );
                }
                dp[start][end] = coins;
            }
        }
        return dp[1][n];
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        // return solve(nums, 1, nums.size() - 2);

        // vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), -1));
        // return solveTD(nums, 1, nums.size() - 2, dp);

        return solveBU(nums);
    }
};