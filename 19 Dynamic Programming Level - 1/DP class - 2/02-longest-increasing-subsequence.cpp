// leetcode 300. Longest Increasing Subsequence

class Solution {
public:
    int solveRec(vector<int>&arr, int curr, int prev){
        // base case
        if(curr >= arr.size()){
            return 0;
        }
        // prev: index that was included latest in the traversal
        int inc = 0;
        if(prev == -1 || arr[curr] > arr[prev]){
            inc = 1 + solveRec(arr,curr+1,curr);
        }
        int exc = 0 + solveRec(arr,curr+1,prev);
        int finalAns = max(inc,exc);
        return finalAns;
    }


    // top-down: 
    int solveMem(vector<int>&arr, int curr, int prev, vector<vector<int> >&dp){
        // base case
        if(curr >= arr.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        // prev: index that was included latest in the traversal
        int inc = 0;
        if(prev == -1 || arr[curr] > arr[prev]){
            inc = 1 + solveMem(arr,curr+1,curr,dp);
        }
        int exc = 0 + solveMem(arr,curr+1,prev,dp);
        dp[curr][prev+1] = max(inc,exc);
        return dp[curr][prev+1];
    }


    // bottom-up
    int solveTab(vector<int>&arr, int curr, int prev){
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1,0));
        
        // rec ranges:
        // curr-> 0 to n
        // prev-> -1 to curr
        // reverse it and apply loop
        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr - 1; prev >= -1; prev--){
                int inc = 0;
                if(prev == -1 || arr[curr] > arr[prev]){
                    inc = 1 + dp[curr+1][curr+1];
                }
                int exc = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(inc,exc);
            }
        }
        // return dp[0][-1+1];
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1; //lastIndex
        // return solveRec(nums,curr,prev);

        // OBSERTVATION: prev hamesha curr se peeche rehne wala hai
        int n = nums.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1,-1));
        // return solveMem(nums,curr,prev,dp);

        return solveTab(nums,curr,prev);
    }
};