// gfg: 0-1 Knapsack Problem

class Solution {
  public:
    int solveUsingRecursion(vector<int>&val, vector<int>&wt, int capacity, int index){
        // base case: single item
        if(index == 0){
            if(wt[0]<=capacity){
                return val[0];
            }
            else return 0;
        }
        // include/exclude pattern
        int incl = 0;
        if(wt[index] <= capacity){
            incl = val[index] + solveUsingRecursion(val,wt,capacity-wt[index], index-1);
        }
        int excl = 0 + solveUsingRecursion(val,wt,capacity,index-1);
        int finalAns = max(incl,excl);
        return finalAns;
    }

    // top-down: 2d dp
    int solveUsingMem(vector<int>&val, vector<int>&wt, int capacity, int index, vector<vector<int> >&dp){
        // base case: single item
        if(index == 0){
            if(wt[0]<=capacity){
                return val[0];
            }
            else return 0;
        }
        // step3: check if answer already exist
        if(dp[capacity][index] != -1) return dp[capacity][index];
        // include/exclude pattern
        int incl = 0;
        if(wt[index] <= capacity){
            incl = val[index] + solveUsingMem(val,wt,capacity-wt[index], index-1,dp);
        }
        int excl = 0 + solveUsingMem(val,wt,capacity,index-1,dp);
        // step2: ans return and store
        dp[capacity][index] = max(incl,excl);
        return dp[capacity][index];
    }

    // bottom-up
    int solveUsingTab(int capacity, vector<int>&wt,vector<int>&val){
        int n = val.size();
        // step1: create dp array
        vector<vector<int> > dp(capacity+1, vector<int>(n,0));
        // step2: analyse base case
        for(int w = wt[0]; w<=capacity;w++){
            dp[w][0] = val[0];
        }
        // step3: parameter->range->reverse->run loop
        // rec: 
        // capacity: w -> 0
        // index: n-1 -> 0
        for(int weight = 0; weight<=capacity; weight++){
            for(int index = 1; index<=n-1;index++){
                int incl = 0;
                if(wt[index] <= weight){
                    incl = val[index] + dp[weight-wt[index]][index-1];
                }
                int excl = 0 + dp[weight][index-1];
                // step2: ans return and store
                dp[weight][index] = max(incl,excl);
            }
        }
        // ans return
        return dp[capacity][n-1];
    }

    // space-optimisation
    int solveUsingSO(int capacity, vector<int>&wt,vector<int>&val){
        int n = val.size();
        // vector<vector<int> > dp(capacity+1, vector<int>(n,0));
        vector<int> prev(capacity+1,0);
        vector<int>curr(capacity+1,0);
        // step2: analyse base case
        for(int w = wt[0]; w<=capacity;w++){
            prev[w] = val[0];
        }
        // step3: parameter->range->reverse->run loop
        // rec: 
        // capacity: w -> 0
        // index: n-1 -> 0

        // hume col-wise answer chiye
        for(int index = 1; index<=n-1;index++){
            for(int weight = 0; weight<=capacity; weight++){
                int incl = 0;
                if(wt[index] <= weight){
                    incl = val[index] + prev[weight-wt[index]];
                }
                int excl = 0 + prev[weight];
                // step2: ans return and store
                curr[weight] = max(incl,excl);
            }
            // shifting: don't forget
            prev = curr;
        }
        // ans return
        return prev[capacity];
    }

    int solveUsingSO2(int capacity, vector<int>&wt,vector<int>&val){
        int n = val.size();
        // vector<int> prev(capacity+1,0);
        vector<int>curr(capacity+1,0);
        // step2: analyse base case
        for(int w = wt[0]; w<=capacity;w++){
            curr[w] = val[0];
        }
        for(int index = 1; index<=n-1;index++){
            for(int weight = capacity; weight>=0; weight--){
                int incl = 0;
                if(wt[index] <= weight){
                    incl = val[index] + curr[weight-wt[index]];
                }
                int excl = 0 + curr[weight];
                // step2: ans return and store
                curr[weight] = max(incl,excl);
            }
        }
        // ans return
        return curr[capacity];
    }


    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int capacity = W;
        int n = val.size();
        int index = n - 1;
        // return solveUsingRecursion(val,wt,capacity,index);

        // top-down
        // step1: create dp array
        // vector<vector<int> > dp(capacity+1, vector<int>(n,-1));
        // return solveUsingMem(val,wt,capacity,index,dp);

        // bottom-up
        // return solveUsingTab(capacity,wt,val);

        // space-optimisation
        return solveUsingSO2(capacity,wt,val);
    }
};