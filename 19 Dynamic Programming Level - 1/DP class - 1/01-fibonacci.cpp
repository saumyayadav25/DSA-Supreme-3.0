// leetcode 509. Fibonacci Number


// TOP-DOWN APPROACH
class Solution {
public:
    // approach 1: only recursion ka use krke solve krdia
    int solveUsingRecursion(int n){
        // base case
        if(n==0) return 0;
        if(n==1) return 1;
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
        return ans;
    }
    
    // 1-d dp array: n+1 block created from n to 0
    int solveUsingMemoization(int n,vector<int>&dp){
        // base case
        if(n==0) return 0;
        if(n==1) return 1;
        // step 3: base case ke baad, check if ans already exists or not
        if(dp[n] != -1) return dp[n]; // change hua hai, answer store hua hai
        // step 2: dp array me ans store karo and return kro
        dp[n] = solveUsingMemoization(n-1,dp) + solveUsingMemoization(n-2,dp);
        return dp[n];
    }

    int fib(int n) {
        // step 1: create dp array and pass in function
        vector<int> dp(n+1,-1);
        return solveUsingMemoization(n,dp);
    }
};


// BOTTOM-UP APPROACH
class Solution {
public:
    // approach 1: only recursion ka use krke solve krdia
    int solveUsingRecursion(int n){
        // base case
        if(n==0) return 0;
        if(n==1) return 1;
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
        return ans;
    }
    
    // 1-d dp array: n+1 block created from n to 0
    int solveUsingMemoization(int n,vector<int>&dp){
        // base case
        if(n==0) return 0;
        if(n==1) return 1;
        // step 3: base case ke baad, check if ans already exists or not
        if(dp[n] != -1) return dp[n]; // change hua hai, answer store hua hai
        // step 2: dp array me ans store karo and return kro
        dp[n] = solveUsingMemoization(n-1,dp) + solveUsingMemoization(n-2,dp);
        return dp[n];
    }

    int solveUsingTabulation(int n){
        // step 1: create dp array: 1d dp
        vector<int> dp(n+1,-1);
        // step 2:analyse base cases and update dp array
        dp[0] = 0;
        if(n == 0){
            return 0;
        }
        dp[1] = 1;
        // step 3: check parameter and reverse it and run a loop
        // recursion:n->0
        // reverse: 0->n
        for(int i = 2; i <= n; i++){
            // copy paste
            dp[i] = dp[i-1] + dp[i-2];
        }
        // answer return
        return dp[n]; //recursion me jo pass kia tha wo dalna hai
    }
    
    int fib(int n) {
        return solveUsingTabulation(n);
    }
};


// SPACE - OPTIMISATION
class Solution {
public:
    // approach 1: only recursion ka use krke solve krdia
    int solveUsingRecursion(int n){
        // base case
        if(n==0) return 0;
        if(n==1) return 1;
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
        return ans;
    }
    
    // 1-d dp array: n+1 block created from n to 0
    int solveUsingMemoization(int n,vector<int>&dp){
        // base case
        if(n==0) return 0;
        if(n==1) return 1;
        // step 3: base case ke baad, check if ans already exists or not
        if(dp[n] != -1) return dp[n]; // change hua hai, answer store hua hai
        // step 2: dp array me ans store karo and return kro
        dp[n] = solveUsingMemoization(n-1,dp) + solveUsingMemoization(n-2,dp);
        return dp[n];
    }

    int solveUsingTabulation(int n){
        // step 1: create dp array: 1d dp
        vector<int> dp(n+1,-1);
        // step 2:analyse base cases and update dp array
        dp[0] = 0;
        if(n == 0){
            return 0;
        }
        dp[1] = 1;
        // step 3: check parameter and reverse it and run a loop
        // recursion:n->0
        // reverse: 0->n
        for(int i = 2; i <= n; i++){
            // copy paste
            dp[i] = dp[i-1] + dp[i-2];
        }
        // answer return
        return dp[n]; //recursion me jo pass kia tha wo dalna hai
    }
    
    int solveUsingTabOptimised(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        int prev = 0;
        int curr = 1;
        // step 3: check parameter and reverse it and run a loop
        // recursion:n->0
        // reverse: 0->n
        for(int i = 2; i <= n; i++){
            // copy paste
            // dp[i] = dp[i-1] + dp[i-2];
            int ans = curr + prev;
            prev = curr;
            curr = ans;
        }
        // answer return
        return curr;
    }
    
    int fib(int n) {
        return solveUsingTabOptimised(n);
    }
};
