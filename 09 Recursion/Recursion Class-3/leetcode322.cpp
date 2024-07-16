// leetcode 322: Coin Change
// TLE
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
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};