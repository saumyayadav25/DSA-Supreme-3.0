// leetcode 1981: Minimize the Difference Between Target and Chosen Elements

class Solution {
public:
    int solve(vector<vector<int>>& mat,int&target, int sum, int row){
        // base case
        if(row==mat.size()) return abs(target-sum);
        int ans = INT_MAX;
        for(int col = 0; col<mat[row].size();col++){
            int recAns = solve(mat, target, sum+mat[row][col],row+1);
            ans = min(ans,recAns);
        }
        return ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int sum = 0, row = 0;
        return solve(mat,target, sum, row);
    }
};