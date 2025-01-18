// leetcode 123. Best Time to Buy and Sell Stock III

class Solution {
public:
    // exponential TC
    int solve(vector<int>&prices, int i, int buy, int limit){
        if(i >= prices.size() || limit == 0) return 0;
        int profit = 0;
        if(buy){
            int buyProfit = - prices[i] + solve(prices, i + 1, 0, limit);
            int skipProfit = solve(prices, i + 1, 1, limit);
            profit = max(buyProfit, skipProfit);
        }
        else{
            int sellProfit = prices[i] + solve(prices, i + 1, 1, limit - 1);
            int skipProfit = solve(prices, i + 1, 0, limit);
            profit = max(sellProfit, skipProfit);
        }
        return profit;
    }

    int solveTD(vector<int>&prices, int i, int buy, int limit, vector<vector<vector<int>>>& dp){
        if(i >= prices.size() || limit == 0) return 0;
        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];
        int profit = 0;
        if(buy){
            int buyProfit = - prices[i] + solveTD(prices, i + 1, 0, limit, dp);
            int skipProfit = solveTD(prices, i + 1, 1, limit, dp);
            profit = max(buyProfit, skipProfit);
        }
        else{
            int sellProfit = prices[i] + solveTD(prices, i + 1, 1, limit - 1, dp);
            int skipProfit = solveTD(prices, i + 1, 0, limit, dp);
            profit = max(sellProfit, skipProfit);
        }
        return dp[i][buy][limit] = profit;
    }

    int solveBU(vector<int>&prices, int i, int buy, int limit, vector<vector<vector<int>>>& dp){
        for(int i = prices.size() - 1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                for(int limit = 1; limit < 3; limit++){
                    int profit = 0;
                    if(buy){
                        int buyProfit = - prices[i] + dp[i + 1][0][limit];
                        int skipProfit = dp[i + 1][1][limit];
                        profit = max(buyProfit, skipProfit);
                    }
                    else{
                        int sellProfit = prices[i] + dp[i + 1][1][limit - 1];
                        int skipProfit = dp[i + 1][0][limit];
                        profit = max(sellProfit, skipProfit);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int solveSO(vector<int>&prices, int i, int buy, int limit, vector<vector<vector<int>>>& dp){
        for(int i = prices.size() - 1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                for(int limit = 1; limit < 3; limit++){
                    int profit = 0;
                    if(buy){
                        int buyProfit = - prices[i] + dp[1][0][limit];
                        int skipProfit = dp[1][1][limit];
                        profit = max(buyProfit, skipProfit);
                    }
                    else{
                        int sellProfit = prices[i] + dp[1][1][limit - 1];
                        int skipProfit = dp[1][0][limit];
                        profit = max(sellProfit, skipProfit);
                    }
                    dp[0][buy][limit] = profit;
                }
            }
            dp[1] = dp[0];
        }
        return dp[0][1][2];
    }

    int maxProfit(vector<int>& prices) {
        // return solve(prices, 0, 1, 2);

        // vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        // return solveTD(prices,0, 1, 2, dp);

        // vector<vector<vector<int>>>dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // return solveBU(prices, 0, 1, 2, dp);

        vector<vector<vector<int>>>dp(2, vector<vector<int>>(2, vector<int>(3, 0)));
        return solveSO(prices, 0, 1, 2, dp);
    }
};