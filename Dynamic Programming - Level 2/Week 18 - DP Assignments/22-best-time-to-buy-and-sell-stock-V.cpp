// leetcode 714. Best Time to Buy and Sell Stock with Transaction Fee

class Solution {
public:
    int solve(vector<int>&prices, int i, int buy, int&fee){
        if(i >= prices.size()) return 0;
        int profit = 0;
        if(buy){
            int buyProfit = - prices[i] + solve(prices, i + 1, 0, fee);
            int skipProfit = solve(prices, i + 1, 1, fee);
            profit = max(buyProfit, skipProfit);
        }
        else{
            int sellProfit = prices[i] + solve(prices, i + 1, 1, fee) - fee; // 1 transaction completed
            int skipProfit = solve(prices, i + 1, 0, fee);
            profit = max(sellProfit, skipProfit);
        }
        return profit;
    }

    int solveTD(vector<int>&prices, int i, int buy, vector<vector<int>>&dp, int&fee){
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
            int buyProfit = - prices[i] + solveTD(prices, i + 1, 0, dp, fee);
            int skipProfit = solveTD(prices, i + 1, 1, dp, fee);
            profit = max(buyProfit, skipProfit);
        }
        else{
            int sellProfit = prices[i] + solveTD(prices, i + 1, 1, dp, fee) - fee;
            int skipProfit = solveTD(prices, i + 1, 0, dp, fee);
            profit = max(sellProfit, skipProfit);
        }
        return dp[i][buy] = profit;
    }

    // TC/SC: O(2*n) 
    int solveBU(vector<int>&prices, vector<vector<int>>&dp, int&fee){
        for(int i = prices.size() - 1; i >=0 ; i--){
            for(int buy = 0; buy < 2; buy++){
                int profit = 0;
                if(buy){
                    int buyProfit = - prices[i] + dp[i + 1][0];
                    int skipProfit = dp[i + 1][1];
                    profit = max(buyProfit, skipProfit);
                }
                else{
                    int sellProfit = prices[i] + dp[i + 1][1] - fee;
                    int skipProfit = dp[i + 1][0];
                    profit = max(sellProfit, skipProfit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }

    // TC: O(2*n)   SC: O(1)
    int solveSO(vector<int>&prices, vector<vector<int>>&dp, int &fee){
        for(int i = prices.size() - 1; i >=0 ; i--){
            for(int buy = 0; buy < 2; buy++){
                int profit = 0;
                if(buy){
                    int buyProfit = - prices[i] + dp[1][0];
                    int skipProfit = dp[1][1];
                    profit = max(buyProfit, skipProfit);
                }
                else{
                    int sellProfit = prices[i] + dp[1][1] - fee;
                    int skipProfit = dp[1][0];
                    profit = max(sellProfit, skipProfit);
                }
                dp[0][buy] = profit;
            }
            dp[1] = dp[0];
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        // return solve(prices, 0, true, fee);

        // vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        // return solveTD(prices, 0, true, dp, fee);

        // vector<vector<int>>dp(prices.size() + 1, vector<int>(2, 0));
        // return solveBU(prices, dp, fee);

        vector<vector<int>>dp(2, vector<int>(2, 0));
        return solveSO(prices, dp, fee);
    }
};