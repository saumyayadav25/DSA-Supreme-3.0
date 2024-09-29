// leetcode 279. Perfect Squares

class Solution {
public:
    int numSquareHelper(int n){
        // base case
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

    // TC: O(N(rootN))-> O(N)
    // SC: O(N)
    int numSquareMem(int n,vector<int>&dp){
        // base case
        if(n == 0) return 1;
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i <= end){
            int perfectSquare = i * i;
            int numberOfPerfectSquares = 1 + numSquareMem(n-perfectSquare, dp);
            if(numberOfPerfectSquares < ans) ans = numberOfPerfectSquares;
            i++;
        }
        dp[n] = ans;
        return dp[n];
    }

    // TC and SC same as top-down
    int numSquareTab(int n){
        vector<int>dp(n+1,-1);
        dp[0] = 1;
        for(int i = 1; i<= n; i++){
            int ans = INT_MAX;
            int start = 1;
            int end = sqrt(i);
            while(start <= end){
                int perfectSquare = start * start;
                int numberOfPerfectSquares = 1 + dp[i - perfectSquare];
                if(numberOfPerfectSquares < ans) ans = numberOfPerfectSquares;
                start++;
            }
            dp[i] = ans;
        }
        
        return dp[n];
    }

    int numSquares(int n) {
        // return numSquareHelper(n)-1;

        // vector<int>dp(n+1,-1);
        // return numSquareMem(n,dp)-1;

        return numSquareTab(n)-1;
    }
};