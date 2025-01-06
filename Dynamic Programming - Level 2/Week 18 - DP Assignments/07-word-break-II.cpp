// leetcode 140. Word Break II

class Solution {
public:
    vector<string> solve(string&s, unordered_map<string, bool> &dict, int i){
        if(i == s.size()) return {""};
        vector<string>ans;
        string word;
        for(int j = i; j < s.size(); j++){
            word.push_back(s[j]);
            if(dict.find(word) == dict.end()) continue;
            // found a valid word
            auto right = solve(s, dict, j + 1);
            for(auto eachRighPart : right){
                string endPart;
                if(eachRighPart.size() > 0) endPart = " " + eachRighPart;
                ans.push_back(word + endPart);
            }
        }
        return ans;
    }

    unordered_map<int, vector<string>> dp;
    vector<string> solveTD(string&s, unordered_map<string, bool> &dict, int i){
        if(i == s.size()) return {""};
        if(dp.find(i) != dp.end()) return dp[i];
        vector<string>ans;
        string word;
        for(int j = i; j < s.size(); j++){
            word.push_back(s[j]);
            if(dict.find(word) == dict.end()) continue;
            // found a valid word
            auto right = solveTD(s, dict, j + 1);
            for(auto eachRighPart : right){
                string endPart;
                if(eachRighPart.size() > 0) endPart = " " + eachRighPart;
                ans.push_back(word + endPart);
            }
        }
        return dp[i] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for(auto word: wordDict){
            dict[word] = 1;
        }
        // return solve(s, dict, 0);
        return solveTD(s, dict, 0);
    }
};