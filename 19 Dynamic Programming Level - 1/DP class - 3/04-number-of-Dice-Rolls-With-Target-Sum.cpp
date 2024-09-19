// leetcode 1155. Number of Dice Rolls With Target Sum

class Solution {
public:
    long long int mod = 1000000007;
    int solveRec(int n, int k, int target){
        // base
        if(target < 0 || n < 0) return 0;
        if(n == 0 && target == 0) return 1;
        if(n == 0 and target != 0) return 0;
        if(n != 0 && target == 0) return 0;
        
        // recursion logic
        int ans = 0;
        for(int i = 1; i<=k;i++){
            ans += solveRec(n-1,k,target-i);
        }
        return ans;
    }

    // top-down:2d dp
    long long int solveMem(int n, int k, int target,vector<vector<long long int>>&dp){
        // base
        if(target < 0 || n < 0) return 0;
        if(n == 0 && target == 0) return 1;
        if(n == 0 and target != 0) return 0;
        if(n != 0 && target == 0) return 0;

        if(dp[n][target] != -1) return dp[n][target];
        // recursion logic
        long long int ans = 0;
        for(int i = 1; i<=k;i++){
            ans += solveMem(n-1,k,target-i,dp);
        }
        dp[n][target] = ans%mod;
        return dp[n][target];
    }

    // bottom-up
    int solveTab(int n, int k, int target){
        vector<vector<long long int> >dp(n+1,vector<long long int>(target+1,0));

        dp[0][0] = 1;

        for(int N = 1; N <= n; N++){
            for(int t = 1; t <= target; t++){
                long long int ans = 0;
                
                for(int i = 1; i <= k;i++){
                    long long int tempAns = 0;
                    if(t-i >= 0) tempAns += dp[N-1][t-i];
                    ans = (ans%mod) + (tempAns%mod);
                }
                dp[N][t] = ans%mod;
            }
        }
        return dp[n][target];
    }

    // space optimisation
    int solveTabSO(int n, int k, int target){
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);

        prev[0] = 1;

        for(int N = 1; N <= n; N++){
            for(int t = 1; t <= target; t++){
                long long int ans = 0;
                
                for(int i = 1; i <= k;i++){
                    long long int tempAns = 0;
                    if(t-i >= 0) tempAns += prev[t-i];
                    ans = (ans%mod) + (tempAns%mod);
                }
                curr[t] = ans%mod;
            }
            // shifting
            prev = curr;
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // return solveRec(n,k,target);

        // vector<vector<long long int> >dp(n+1,vector<long long int>(target+1,-1));
        // return solveMem(n,k,target,dp);

        // return solveTab(n,k,target);

        return solveTabSO(n,k,target);
    }
};