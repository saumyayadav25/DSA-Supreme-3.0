// leetcode 1406. Stone Game III

class Solution {
public:
    // exponential TC
    int solve(vector<int>&stoneValue, int i){
        if(i == stoneValue.size()) return 0;
        int ans = INT_MIN;
        int total = 0;
        for(int X = 1; X <= 3; X++){ // X: how many stone picked
            if(i + X - 1 >= stoneValue.size()) break;
            total += stoneValue[i + X - 1];
            ans = max(ans, total - solve(stoneValue, i + X));
        }
        return ans;
    }
    
    int solveTD(vector<int>&stoneValue, int i, vector<int>&dp){
        if(i == stoneValue.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MIN;
        int total = 0;
        for(int X = 1; X <= 3; X++){ // X: how many stone picked
            if(i + X - 1 >= stoneValue.size()) break;
            total += stoneValue[i + X - 1];
            ans = max(ans, total - solveTD(stoneValue, i + X, dp));
        }
        return dp[i] = ans;
    }

    int solveBU(vector<int>&stoneValue){
        vector<int>dp(stoneValue.size() + 1, 0);
        for(int i = stoneValue.size() - 1; i >= 0; i--){
            int ans = INT_MIN;
            int total = 0;
            for(int X = 1; X <= 3; X++){ // X: how many stone picked
                if(i + X - 1 >= stoneValue.size()) break;
                total += stoneValue[i + X - 1];
                ans = max(ans, total - dp[i + X]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        // int ans = solve(stoneValue, 0); // A - B

        // vector<int>dp(stoneValue.size() + 1, - 1);
        // int ans = solveTD(stoneValue, 0, dp);

        int ans = solveBU(stoneValue);
        if(ans > 0) return "Alice";
        if(ans < 0) return "Bob";
        return "Tie";
    }
};