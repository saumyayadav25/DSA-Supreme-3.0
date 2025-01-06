// lc 139. Word Break

class Solution {
public:
    bool check(vector<string>&wordDict, string&s){
        for(auto i : wordDict){
            if(s == i) return true;
        }
        return false;
    }
    bool solve(string &s, vector<string>& wordDict, int start){
        if(start == s.size()) return true;
        // 1 case, make a string
        string word = "";
        bool flag = false;
        for(int i = start; i < s.size(); i++){
            word += s[i];
            if(check(wordDict, word)){
                flag = flag || solve(s, wordDict, i + 1);
            }
        }
        return flag;
    }

    bool solveTD(string &s, vector<string>& wordDict, int start, vector<int>&dp){
        if(start == s.size()) return true;
        if(dp[start] != -1) return dp[start];
        // 1 case, make a string
        string word = "";
        bool flag = false;
        for(int i = start; i < s.size(); i++){
            word += s[i];
            if(check(wordDict, word)){
                flag = flag || solveTD(s, wordDict, i + 1, dp);
            }
        }
        return dp[start] = flag;
    }

    bool solveBU(string&s, vector<string>& wordDict, vector<int>& dp){
        for(int start = s.size() - 1; start >= 0; start--){
            string word = "";
            bool flag = false;
            for(int i = start; i < s.size(); i++){
                word += s[i];
                if(check(wordDict, word)){
                    flag = flag || dp[i+1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // return solve(s, wordDict, 0);

        // vector<int>dp(s.size(),-1);
        // return solveTD(s, wordDict, 0,dp);

        vector<int>dp(s.size() + 1, true);
        return solveBU(s, wordDict, dp);
    }
};