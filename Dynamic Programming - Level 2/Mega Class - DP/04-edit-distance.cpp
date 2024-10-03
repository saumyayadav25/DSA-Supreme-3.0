// leetcode 72. Edit Distance

class Solution{
public:
    int solveRE(string &word1, string &word2, int i, int j){
        if (i == word1.length())
            return word2.length() - j; // Insert remaining characters of word2
        if (j == word2.length())
            return word1.length() - i; // Remove remaining characters of word1

        // If current characters match, move to the next index
        if (word1[i] == word2[j])
            return solveRE(word1, word2, i + 1, j + 1);

        // If current characters don't match, we have three options:
        int insertOp = solveRE(word1, word2, i, j + 1);      // Insert a character into word1
        int removeOp = solveRE(word1, word2, i + 1, j);      // Remove a character from word1
        int replaceOp = solveRE(word1, word2, i + 1, j + 1); // Replace the character in word1

        // Take the minimum of the three operations and add 1 (for the current operation)
        return 1 + min({insertOp, removeOp, replaceOp});
    }

    int solveMem(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        if (i == word1.length())
            return word2.length() - j; 
        if (j == word2.length())
            return word1.length() - i; 
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (word1[i] == word2[j])
            ans = solveMem(word1, word2, i + 1, j + 1, dp);
        else{
            // If current characters don't match, we have three options:
            int insertOp = solveMem(word1, word2, i, j + 1, dp);    
            int removeOp = solveMem(word1, word2, i + 1, j, dp);     
            int replaceOp = solveMem(word1, word2, i + 1, j + 1, dp); 

            // Take the minimum of the three operations and add 1 (for the current operation)
            ans = 1 + min({insertOp, removeOp, replaceOp});
        }
        return dp[i][j] = ans;
    }

    int solveTab(string &word1, string &word2){
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int j = 0; j <= word2.size(); j++){
            dp[word1.size()][j] = word2.size() - j;
        }
        for (int i = 0; i <= word1.size(); i++){
            dp[i][word2.size()] = word1.size() - i;
        }
        for (int i = word1.size() - 1; i >= 0; i--){
            for (int j = word2.size() - 1; j >= 0; j--){
                int ans = 0;
                if (word1[i] == word2[j]) ans = dp[i + 1][j + 1];
                else{
                    // If current characters don't match, we have three options:
                    int insertOp = dp[i][j + 1];  
                    int removeOp = dp[i + 1][j];    
                    int replaceOp = dp[i + 1][j + 1]; 
                    // Take the minimum of the three operations and add 1 (for the current operation)
                    ans = 1 + min({insertOp, removeOp, replaceOp});
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveSO(string &word1, string &word2){
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        vector<int> curr(word2.size() + 1, 0);
        vector<int> next(word2.size() + 1, 0);
        for (int j = 0; j <= word2.size(); j++){
            next[j] = word2.size() - j;
        }
        for (int i = word1.size() - 1; i >= 0; i--){
            for (int j = word2.size() - 1; j >= 0; j--){
                curr[word2.size()] = word1.size() - i;
                int ans = 0;
                if (word1[i] == word2[j])
                    ans = next[j + 1];
                else{
                    // If current characters don't match, we have three options:
                    int insertOp = curr[j + 1]; 
                    int removeOp = next[j];    
                    int replaceOp = next[j + 1]; 
                    // Take the minimum of the three operations and add 1 (for the current operation)
                    ans = 1 + min({insertOp, removeOp, replaceOp});
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }

    int minDistance(string word1, string word2){
        // return solveRE(word1, word2, 0, 0);

        // vector<vector<int>>dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        // return solveMem(word1, word2, 0, 0, dp);

        // return solveTab(word1, word2);
        return solveSO(word1, word2);
    }
};