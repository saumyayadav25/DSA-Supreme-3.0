// leetcode 474. Ones and Zeroes

class Solution {
public:
    void convertStrsToNumStrs(vector<string>&strs, vector<pair<int, int>>&numStrs){
        for(auto str : strs){
            int zeroes = 0, ones = 0;
            for(auto ch : str){
                if(ch == '0') zeroes++;
                else ones++;
            }
            numStrs.push_back({zeroes, ones});
        }
    }

    int solve(vector<pair<int,int>>&numStrs, int i, int m, int n){
        if(i == numStrs.size()) return 0;
        int zeroes = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        if(m - zeroes >= 0 && n - ones >= 0) include = 1 + solve(numStrs, i + 1, m - zeroes, n - ones);
        exclude = solve(numStrs, i + 1, m, n);
        return max(include, exclude);
    }

    int solveTD(vector<pair<int,int>>&numStrs, int i, int m, int n, vector<vector<vector<int>>>&dp){
        if(i == numStrs.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int zeroes = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        if(m - zeroes >= 0 && n - ones >= 0) include = 1 + solveTD(numStrs, i + 1, m - zeroes, n - ones, dp);
        exclude = solveTD(numStrs, i + 1, m, n, dp);
        return dp[i][m][n] = max(include, exclude);
    }

    int solveBU(vector<pair<int,int>>&numStrs, int m, int n){
        vector<vector<vector<int>>>dp(numStrs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for(int i = numStrs.size() - 1; i >= 0; i--){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    int zeroes = numStrs[i].first;
                    int ones = numStrs[i].second;
                    int include = 0, exclude = 0;
                    if(j - zeroes >= 0 && k - ones >= 0) include = 1 + dp[i + 1][j - zeroes][k - ones]; //solveTD(numStrs, i + 1, m - zeroes, n - ones, dp);
                    exclude = dp[i + 1][j][k]; //solveTD(numStrs, i + 1, m, n, dp);
                    dp[i][j][k] = max(include, exclude);
                }
            }
        }
        return dp[0][m][n];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> numStrs; // {no. of 0's, no. of 1's}
        convertStrsToNumStrs(strs, numStrs);

        // return solve(numStrs, 0, m, n);

        // vector<vector<vector<int>>>dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        // return solveTD(numStrs, 0, m, n, dp);

        return solveBU(numStrs, m, n);
    }
};