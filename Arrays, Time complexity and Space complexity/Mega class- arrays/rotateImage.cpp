//leetcode 48: rotate image
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //step-1: transpose
        int nrows=matrix.size();
        int ncols=matrix[0].size();

        for(int i=0; i<nrows;i++){
            for(int j=i;j<ncols;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //step-2: reverse row-wise
        for(int i=0;i<nrows;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
