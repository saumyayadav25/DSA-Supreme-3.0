//leetcode 1047: remove all adjacent duplicates in String
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int n = s.length();
        for(int i=0;i<n;i++){
            char currcharacter = s[i];
            if(ans.empty() || currcharacter != ans.back()){
                ans.push_back(currcharacter);
            }
            else if(currcharacter == ans.back()){ //rightmost character
                ans.pop_back();
            }
        }
        return ans;
    }
};

