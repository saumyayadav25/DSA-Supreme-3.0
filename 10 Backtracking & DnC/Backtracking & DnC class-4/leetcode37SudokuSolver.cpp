// leetcode 37 : Sudoku Solver
class Solution {
public:
    bool isSafe(int digit, int row, int col, vector<vector<char>>& board){
        //row Check
        int n=board.size();
        for(int k=0; k<n;k++){
            if(board[row][k] == digit){
                //same digit already exists in same row
                return false;
            }
        }
        //column Check
        for(int k=0; k<n;k++){
            if(board[k][col] == digit){
                //same digit already exists in same col
                return false;
            }
        }
        //3*3 sub-box Check
        for(int k=0;k<n;k++){
            if(board[3*(row/3)+k/3][3*(col/3)+k%3] == digit){
                //same digit already exists in 3*3 box
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        //base case-?
        //recursion
        //find the empty cell first->'.'
        for(int i=0; i<board.size();i++){
            for(int j=0; j<board[0].size();j++){
                if(board[i][j]=='.'){
                    //fill the empty cell-> 1 to 9 digits hit and trial
                    for(int digit = '1'; digit<='9'; digit++){
                        //which digit ko place?
                        //check which digit is safe to place
                        if(isSafe(digit,i,j,board)==true){
                            board[i][j]=digit;
                            //baaki recursion rkhdega
                            //aage solve ho paya?
                            bool couldSolveNext = solve(board);
                            if(couldSolveNext == true ) return true;
                            else{
                                //backtrack-> maybe wrong digit placed
                                board[i][j]='.';
                            }
                        }
                    }
                    //1-9: no digit placed-> phle kahi galti kri hai
                    return false;
                }
            }
        }
        //board filled completely
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};