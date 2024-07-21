// leetcode 22: Generate Parentheses
class Solution {
public:
    void solve(vector<string>&ans, string out, int open, int close, int n){
        // base case
        if(open+close==2*n){
            ans.push_back(out);
            return;
        }

        if(open<n){
            solve(ans, out + "(", open + 1, close, n);
        }
        if(close<open){
            solve(ans, out + ")", open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", 0, 0, n);
        return ans;
    }
};