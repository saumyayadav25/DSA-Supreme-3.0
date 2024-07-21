// leetcode 79: Word Search
class Solution {
public:
    bool solve(vector<vector<char>>& B, string&word, int row, int col, int i){
        if(i==word.size()) // all chars matched->found
            return true;
        if(row<0 || row>=B.size() || col<0 || col>=B[0].size() || B[row][col]!=word[i] || B[row][col]=='%') return false;
        // reached here means, current ith word char has matched
        char temp = B[row][col];
        // mark visited
        B[row][col]='%';

        // down, up, right,left
        bool found = solve(B, word, row+1, col,i+1) || solve(B, word, row-1, col,i+1) || solve(B, word, row, col+1,i+1) || solve(B, word, row, col-1,i+1);
        // unvisit
        B[row][col]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size();j++){
                if(solve(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};