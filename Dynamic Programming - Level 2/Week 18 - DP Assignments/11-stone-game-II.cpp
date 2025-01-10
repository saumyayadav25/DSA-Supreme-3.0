// leetcode 1140. Stone Game II

class Solution {
public:
    int solve(vector<int>&piles, int i, int M, int aliceTurn){
        if(i == piles.size()) return 0;
        int ans = aliceTurn ? INT_MIN : INT_MAX;
        int total = 0;
        for(int X = 1; X <= 2 * M; X++){
            if(i + X - 1 >= piles.size()) break;
            total += piles[i + X - 1];
            if(aliceTurn) ans = max(ans, total + solve(piles, i + X, max(X, M), !aliceTurn));
            else ans = min(ans, solve(piles, i + X, max(X, M), !aliceTurn));
        }
        return ans;
    }

    int solveTD(vector<int>&piles, int i, int M, int aliceTurn, vector<vector<vector<int>>>&dp){
        if(i == piles.size()) return 0;
        if(dp[i][M][aliceTurn] != -1) return dp[i][M][aliceTurn];
        int ans = aliceTurn ? INT_MIN : INT_MAX;
        int total = 0;
        for(int X = 1; X <= 2 * M; X++){
            if(i + X - 1 >= piles.size()) break;
            total += piles[i + X - 1];
            if(aliceTurn) ans = max(ans, total + solveTD(piles, i + X, max(X, M), !aliceTurn, dp));
            else ans = min(ans, solveTD(piles, i + X, max(X, M), !aliceTurn, dp));
        }
        return dp[i][M][aliceTurn] = ans;
    }

    int solveBU(vector<int>&piles){
        vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size()+1, vector<int>(2, 0)));
        for(int i = piles.size() - 1; i >= 0; i--){
            for(int M = piles.size(); M >= 1; M--){
                for(int aliceTurn = 0; aliceTurn <= 1; aliceTurn++){
                    int ans = aliceTurn ? INT_MIN : INT_MAX;
                    int total = 0;
                    for(int X = 1; X <= 2 * M; X++){
                        if(i + X - 1 >= piles.size()) break;
                        total += piles[i + X - 1];
                        if(aliceTurn) ans = max(ans, total + dp[i + X][max(X,M)][!aliceTurn]);
                        else ans = min(ans, dp[i + X][max(X,M)][!aliceTurn]);
                    }
                    dp[i][M][aliceTurn] = ans;
                }
            }
        }
        return dp[0][1][1];
    }

    int stoneGameII(vector<int>& piles) {
        // return solve(piles, 0, 1, true);

        // vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size()+1, vector<int>(2, -1)));
        // return solveTD(piles, 0, 1, true, dp);

        return solveBU(piles);
    }
};