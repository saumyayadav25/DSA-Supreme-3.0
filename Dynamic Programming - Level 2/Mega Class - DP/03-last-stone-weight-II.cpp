// leetcode 1049. Last Stone Weight II

class Solution {
    int totalSum = 0;
public:
    int solveRec(vector<int>&stones, int i, int sum){
        if(i==stones.size()){
            if(sum < 0) return INT_MAX; //we want to completely ignore sum < 0. in finalAns we are taking min, isliye return INT_MAX;
            return sum;
        }
        int pos = solveRec(stones,i+1,sum + stones[i]);
        int neg = solveRec(stones,i+1,sum - stones[i]);
        return min(pos,neg);
    }

    int solveMem(vector<int>&stones, int i, int sum,vector<vector<int>>&dp){
        if(i==stones.size()){
            if(sum < 0) return INT_MAX; //we want to completely ignore sum < 0. in finalAns we are taking min, isliye return INT_MAX;
            return sum;
        }
        if(dp[i][sum+totalSum] != -1) return dp[i][sum+totalSum];
        int pos = solveMem(stones,i+1,sum + stones[i],dp);
        int neg = solveMem(stones,i+1,sum - stones[i],dp);
        return dp[i][sum+totalSum] = min(pos,neg);
    }

    int solveTab(vector<int>&stones){
        vector<vector<int>>dp(stones.size()+1,vector<int>(2*totalSum + 1,0));
        for(int sum = -totalSum; sum <= totalSum; sum++){
            dp[stones.size()][sum+totalSum] = sum < 0? INT_MAX:sum;
        }
        for(int i = stones.size()-1; i>=0;i--){
            for(int j = totalSum; j >= -totalSum; j--){
                int pos = INT_MAX, neg = INT_MAX;
                if(j+stones[i] <= totalSum){
                    pos = dp[i + 1][totalSum + j + stones[i]];
                }
                if(j - stones[i] >= -totalSum){
                    neg = dp[i + 1][totalSum + j - stones[i]];
                }
                dp[i][j + totalSum] = min(pos,neg);
            }
        }
        return dp[0][totalSum];
    }

    int solveTabSO(vector<int>&stones){
        vector<int>curr(2*totalSum + 1, 0);
        vector<int>next(2*totalSum + 1, 0);
        for(int sum = -totalSum; sum <= totalSum; sum++){
            next[sum+totalSum] = sum < 0? INT_MAX:sum;
        }
        for(int i = stones.size()-1; i>=0;i--){
            for(int j = totalSum; j >= -totalSum; j--){
                int pos = INT_MAX, neg = INT_MAX;
                if(j+stones[i] <= totalSum){
                    pos = next[totalSum + j + stones[i]];
                }
                if(j - stones[i] >= -totalSum){
                    neg = next[totalSum + j - stones[i]];
                }
                curr[j + totalSum] = min(pos,neg);
            }
            next = curr;
        }
        return curr[totalSum];
    }

    int lastStoneWeightII(vector<int>& stones) {
        // return solveRec(stones, 0, 0);

        totalSum = accumulate(stones.begin(),stones.end(),0);
        // vector<vector<int>>dp(stones.size()+1,vector<int>(2*totalSum + 1,-1));
        // return solveMem(stones,0,0,dp);

        // return solveTab(stones);
        return solveTabSO(stones);
    }
};




// partition method
class Solution {
    int totalSum = 0;
public:
    // sum is denoting summation of G1 stones
    int solveRE(vector<int>&stones, int i, int sum){
        if(i==stones.size()){
            // the sum is done for current G1
            int g1sum = sum;
            int g2sum = totalSum - sum;
            return abs(g1sum - g2sum);
        }
        // 1 case, i'll try to include ith stone into G1, and exclude
        int incl = solveRE(stones, i + 1, sum + stones[i]);
        int excl = solveRE(stones, i + 1, sum);
        return min(incl,excl);
    }

    int solveMem(vector<int>&stones, int i, int sum,vector<vector<int>>&dp){
        if(i==stones.size()){
            // the sum is done for current G1
            int g1sum = sum;
            int g2sum = totalSum - sum;
            return abs(g1sum - g2sum);
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        // 1 case, i'll try to include ith stone into G1, and exclude
        int incl = solveMem(stones, i + 1, sum + stones[i],dp);
        int excl = solveMem(stones, i + 1, sum,dp);
        return dp[i][sum] = min(incl,excl);
    }

    int solveTab(vector<int>&stones){
        vector<vector<int>>dp(stones.size()+1, vector<int>(totalSum+1,0));
        // how g1sum can vary? [0, totalSum]
        for(int i = 0; i <= totalSum; i++){
            int g1sum = i;
            int g2sum = totalSum - i;
            dp[stones.size()][i] = abs(g1sum - g2sum);
        }
        for(int i = stones.size() - 1; i >= 0; i--){
            for(int j = totalSum; j >= 0; j--){
                int incl = INT_MAX;
                if(j + stones[i] <= totalSum)
                    incl = dp[i + 1][j + stones[i]]; 
                int excl = dp[i + 1][j]; 
                dp[i][j] = min(incl,excl);
            }
        }
        return dp[0][0];
    }

    int solveTabSO(vector<int>&stones){
        vector<int>curr(totalSum + 1, 0);
        vector<int>next(totalSum + 1, 0);

        for(int i = 0; i <= totalSum; i++){
            int g1sum = i;
            int g2sum = totalSum - i;
            next[i] = abs(g1sum - g2sum);
        }
        for(int i = stones.size() - 1; i >= 0; i--){
            for(int j = totalSum; j >= 0; j--){
                int incl = INT_MAX;
                if(j + stones[i] <= totalSum)
                    incl = next[j + stones[i]]; 
                int excl = next[j]; 
                curr[j] = min(incl,excl);
            }
            next = curr;
        }
        return curr[0];
    }

    int lastStoneWeightII(vector<int>& stones) {
        totalSum = accumulate(stones.begin(),stones.end(),0);
        // return solveRE(stones,0,0);

        // vector<vector<int>>dp(stones.size()+1, vector<int>(totalSum+1,-1));
        // return solveMem(stones,0,0,dp);

        // return solveTab(stones);

        return solveTabSO(stones);
    }
};