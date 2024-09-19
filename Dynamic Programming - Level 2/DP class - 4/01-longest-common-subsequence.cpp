// leetcode 1143. Longest Common Subsequence

class Solution {
public:
    int solveRec(string text1, string text2, int i, int j){
        // base case
        if(i >= text1.length()) return 0;
        if(j >= text2.length()) return 0;
        int ans = 0;
        // match
        if(text1[i] == text2[j]){
            ans = 1 + solveRec(text1, text2, i+1,j+1);
        }
        else{ // no match
            ans = 0 + max(solveRec(text1,text2,i+1,j),solveRec(text1, text2,i,j+1));
        }
        return ans;
    }
    
    int solveMem(string &text1, string &text2, int i, int j, vector<vector<int>>&dp){
        // base case
        if(i >= text1.length()) return 0;
        if(j >= text2.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        // match
        if(text1[i] == text2[j]){
            ans = 1 + solveMem(text1, text2, i+1,j+1,dp);
        }
        else{ // no match
            ans = 0 + max(solveMem(text1,text2,i+1,j,dp),solveMem(text1, text2,i,j+1,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTab(string text1, string text2){
        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1,0));
        for(int i = text1.length()-1; i>=0;i--){
            for(int j = text2.length()-1; j>=0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                else{ // no match
                    ans = 0 + max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    
    int solveTabSO(string text1, string text2){
        vector<int>prev(text2.length()+1,0);
        vector<int>curr(text2.length()+1,0);
        for(int i = text1.length()-1; i>=0;i--){
            for(int j = text2.length()-1; j>=0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + prev[j+1];
                }
                else{ // no match
                    ans = 0 + max(prev[j],curr[j+1]);
                }
                curr[j] = ans;
            }
            // shifting
            prev = curr;
        }
        return prev[0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        // return solveRec(text1,text2,i,j);

        // vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1,-1));
        // return solveMem(text1,text2,i,j,dp);

        // return solveTab(text1, text2);

        return solveTabSO(text1,text2);
    }
};