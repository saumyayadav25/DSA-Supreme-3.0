// leetcode 279: Perfect Squares

class Solution {
public:
    int numSquareHelper(int n){
        // base
        if(n == 0) return 1;
        if(n<0) return 0;
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i <= end){
            int perfectSquare = i * i;
            int numberOfPerfectSquares = 1 + numSquareHelper(n-perfectSquare);
            if(numberOfPerfectSquares < ans) ans = numberOfPerfectSquares;
            i++;
        }
        return ans;
    }
    int numSquares(int n) {
        return numSquareHelper(n)-1;
    }
};