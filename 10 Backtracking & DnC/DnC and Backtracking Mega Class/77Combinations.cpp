// leetcode 77: Combinations
class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>&curr, int k, int start, int n){
        // base case
        if(k==0){
            ans.push_back(curr);
            return;
        }

        // ek case
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            solve(ans, curr, k-1 ,i+1 , n);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, curr, k, 1,n);
        return ans;
    }
};