//leetcode 74
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows= matrix.size();
        int columns = matrix[0].size();
        int n=rows*columns;
        
        int s=0;
        int e=n-1;
        int mid = s+(e-s)/2;
        while(s<=e){
            int rowIndex = mid/columns;
            int colIndex = mid%columns;
            if(matrix[rowIndex][colIndex] == target){
                return true;
            }
            if(matrix[rowIndex][colIndex] < target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid = s+(e-s)/2;
        }
        return false;
    }
};
