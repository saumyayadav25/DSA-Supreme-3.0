// leetcode 120. Triangle

class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col){
        if(row==triangle.size()-1){
            return triangle[row][col];
        }
        int down = triangle[row][col] + solve(triangle, row+1, col);
        int plus = triangle[row][col] + solve(triangle, row+1, col+1);
        return min(down, plus);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle, 0,0);
    }
};