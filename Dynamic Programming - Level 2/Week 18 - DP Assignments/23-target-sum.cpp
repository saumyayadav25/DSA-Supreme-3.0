// leetcode 494. Target Sum

class Solution {
public:
    int solve(vector<int>&nums, int target, int i){
        if(i == nums.size()) return target == 0 ? 1 : 0;
        int plus = solve(nums, target - nums[i], i + 1);
        int minus = solve(nums, target + nums[i], i + 1);
        return plus + minus;
    }

    int solveTD(vector<int>&nums, int target, int i, map<pair<int,int>,int>&dp){
        if(i == nums.size()) return target == 0 ? 1 : 0;
        if(dp.find({i,target}) != dp.end()) return dp[{i, target}];
        int plus = solveTD(nums, target - nums[i], i + 1, dp);
        int minus = solveTD(nums, target + nums[i], i + 1, dp);
        return dp[{i, target}] = plus + minus;
    }

    int solveBU(vector<int>&nums, int target){
        map<pair<int,int>, int>dp;
        dp[{nums.size(), 0}] = 1;

        int total = 0;
        for(auto num: nums) total += num;
        for(int i = nums.size() - 1; i >= 0; i--){
            for(int sum = -total; sum <= total; sum++){
                int plus = dp.find({i + 1, sum - nums[i]}) != dp.end() ? dp[{i + 1, sum - nums[i]}] : 0; //solveTD(nums, target - nums[i], i + 1, dp);
                int minus = dp.find({i + 1, sum + nums[i]}) != dp.end() ? dp[{i + 1, sum + nums[i]}] : 0; //solveTD(nums, target + nums[i], i + 1, dp);
                dp[{i, sum}] = plus + minus;
            }
        }
        return dp[{0, target}];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // return solve(nums, target, 0);

        // map<pair<int,int>, int>dp; // {i, target} -> number of ways
        // return solveTD(nums, target, 0, dp);

        return solveBU(nums, target);
    }
};