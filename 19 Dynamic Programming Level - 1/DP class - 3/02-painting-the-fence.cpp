// gfg: Painting the Fence

class Solution{
    public:
    long long mod = 1000000007;
    long long solveRec(int n, int k){
        // base case
        if(n==1) return k;
        if(n==2) return (k + k*(k-1));
        int ans = (k-1) * (solveRec(n-1,k) + solveRec(n-2,k));
        return ans;
    }

    // top-down
    long long solveMem(int n,long long k,vector<long long int>&dp){
        // base case
        if(n==1) return k%mod;
        if(n==2) return (k + k*(k-1))%mod;
        if(dp[n] != -1) return dp[n]%mod;
        long long ans1 = solveMem(n-1,k,dp);
        long long ans2 = solveMem(n-2,k,dp);
        long long ans3 = (ans1+ans2)%mod;
        long long ans4 = ((k-1) * ans3)%mod;
        dp[n] = ans4%mod;
        return dp[n];
    }

    // bottom-up
    long long solveTab(int n, long long k){
        vector<long long>dp(n+1,0);
        dp[1] = k%mod;
        dp[2] = (k + k*(k-1))%mod;
        for(int i = 3; i<=n;i++){
            long long ans = ((k-1)*((dp[i-1]%mod) + (dp[i-2])%mod)%mod)%mod;
            dp[i] = ans;
        }
        return dp[n];
    }

    // space optimisation
    long long solveSO(int n, long long k){
        // vector<long long>dp(n+1,0);
        long long prev2 = k%mod;
        long long prev1 = (k + k*(k-1))%mod;
        if(n==1) return prev2;
        if(n==2) return prev1;
        for(int i = 3; i<=n;i++){
            long long curr = ((k-1)*((prev1%mod) + (prev2)%mod)%mod)%mod;
            // shifting
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }


    long long countWays(int n, int k){
        // return solveRec(n,k);
        // vector<long long>dp(n+1,-1);
        long long newK = k;
        // return solveMem(n,newK,dp);
        return solveTab(n,newK);
        return solveSO(n,newK);
    }
};