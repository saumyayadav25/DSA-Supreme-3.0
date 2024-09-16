// leetcode 322. Coin Change

class Solution {
public:
    int solve(vector<int>& coins, int amount){
        //base case
        if(amount==0){
            //how much coins needed to create 0 amount
            return 0;
        }
        int minCoinAns = INT_MAX;
        //har amount ke liye poore coins ke array ko traverse krenge
        for(int i=0;i<coins.size();i++){
            int coin = coins[i];
            //if coin value > amount value-> no need to call recursive function. else call recursive function
            if(coin <= amount){
                //1 coin used, amount becomes-> amount-coins
                //rest recursion will handle
                int recursionAns = solve(coins, amount-coin);
                //recursionAns can be valid or invalid
                //invalid case-> recursionAns = INT_MAX
                if(recursionAns!=INT_MAX){
                    int coinsUsed = 1+recursionAns;
                    minCoinAns = min(minCoinAns, coinsUsed);
                }
            }
        }
        return minCoinAns;
    }

    // top-down: 1d dp
    int solveMem(vector<int>& coins, int amount,vector<int>&dp){
        //base case
        if(amount==0){
            return 0;
        }
        // step3: check if ans already exists
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int minCoinAns = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int coin = coins[i];
            if(coin <= amount){
                int recursionAns = solveMem(coins, amount-coin,dp);
                if(recursionAns!=INT_MAX){
                    int coinsUsed = 1+recursionAns;
                    minCoinAns = min(minCoinAns, coinsUsed);
                }
            }
        }
        // step2: store ans in dp and return
        dp[amount] = minCoinAns;
        return dp[amount];
    }

    int solveTab(vector<int>&coins, int amount){
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for(int amt = 1; amt <= amount; amt++){
            // logic
            int minCoinAns = INT_MAX;
            for(int i = 0; i < coins.size();i++){
                int coin = coins[i];
                if(coin <= amt){
                    int recursionAns = dp[amt-coin];
                    if(recursionAns!=INT_MAX){
                        int coinsUsed = 1 + recursionAns;
                        minCoinAns = min(minCoinAns,coinsUsed);
                    } 
                }
            }
            dp[amt] = minCoinAns;
        }
        return dp[amount];
    }



    int coinChange(vector<int>& coins, int amount) {
        // int ans = solve(coins, amount);
        
        vector<int>dp(amount+1,-1);
        // int ans = solveMem(coins,amount,dp);
        
        int ans = solveTab(coins,amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};