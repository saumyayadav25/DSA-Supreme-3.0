// lc 5. Longest Palindromic Substring

class Solution {
public:
    int maxLen = 1, start = 0;
    bool isPalindrome(string& s, int i, int j){
        if(i >= j) return true;
        bool flag = false;
        if(s[i] == s[j]) flag = isPalindrome(s, i + 1, j - 1);
        if(flag){
            int currLen = j - i + 1;
            if(currLen > maxLen){
                maxLen = currLen;
                start = i;
            }
        }
        return flag;
    }

    bool isPalindromeDP(string& s, int i, int j, vector<vector<int>>&dp){
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool flag = false;
        if(s[i] == s[j]) flag = isPalindromeDP(s, i + 1, j - 1, dp);
        if(flag){
            int currLen = j - i + 1;
            if(currLen > maxLen){
                maxLen = currLen;
                start = i;
            }
        }
        return dp[i][j] = flag;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, - 1));
        for(int i = 0;i < n; i++){
            for(int j = i;j < n; j++){
                // bool t = isPalindrome(s, i, j);
                bool t = isPalindromeDP(s, i, j, dp);
            }
        }
        return s.substr(start, maxLen);
    }
};