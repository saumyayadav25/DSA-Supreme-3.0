// leetcode 121: Best Time to Buy and Sell Stock

// recursive
class Solution {
public:
    void maxProfitFinder(vector<int>& prices, int i, int &minPrice, int&maxProfit){
        // base case
        if(i==prices.size()) return;
        // 1case
        if(prices[i]<minPrice) minPrice = prices[i];
        int todaysProfit = prices[i]-minPrice;
        if(todaysProfit>maxProfit) maxProfit = todaysProfit;
        // Recursive call
        maxProfitFinder(prices, i+1, minPrice,maxProfit);
    }
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        maxProfitFinder(prices,0,minPrice, maxProfit);
        return maxProfit;
    }
};



// iterative approach: TC:O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size() ; i++){
            if(prices[i]<minPrice){
                minPrice = prices[i];
            }
            int todayProfit = prices[i] - minPrice;
            max_profit = max(todayProfit, max_profit);
        }
        return max_profit;
    }
};
