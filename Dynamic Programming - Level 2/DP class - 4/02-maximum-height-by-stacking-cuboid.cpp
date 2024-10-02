// leetcode 1691. Maximum Height by Stacking Cuboids

class Solution {
public:
    bool isSafeToPlace(vector<int>c1, vector<int>c2){
        if(c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]) return true;
        else return false;
    }

    int solveRec(vector<vector<int>>& cuboids, int curr, int prev){
        // base case
        if(curr >= cuboids.size()){
            return 0;
        }

        // inc / exc pattern
        int incl = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
            incl = cuboids[curr][2] + solveRec(cuboids,curr+1,curr);
        }
        int excl = 0 + solveRec(cuboids, curr+1,prev);
        int finalAns = max(incl,excl);
        return finalAns;
    }

    int solveMem(vector<vector<int>>& cuboids, int curr, int prev,vector<vector<int> >&dp){
        // base case
        if(curr >= cuboids.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        // inc / exc pattern
        int incl = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
            incl = cuboids[curr][2] + solveMem(cuboids,curr+1,curr,dp);
        }
        int excl = 0 + solveMem(cuboids, curr+1,prev,dp);
        dp[curr][prev+1] = max(incl,excl);
        return dp[curr][prev+1];
    }

    int solveTab(vector<vector<int>>&cuboids){
        int n = cuboids.size();
        vector<vector<int> >dp(n+1,vector<int>(n+1,0));
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1;prev--){
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
                    incl = cuboids[curr][2] + dp[curr+1][curr+1];
                }
                int excl = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(incl,excl);
            }
        }
        return dp[0][-1+1];
    }

    int solveTabSO(vector<vector<int>>&cuboids){
        int n = cuboids.size();
        // vector<vector<int> >dp(n+1,vector<int>(n+1,0));
        vector<int>prevRow(n+1,0);
        vector<int>currRow(n+1,0);
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1;prev--){
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
                    incl = cuboids[curr][2] + prevRow[curr+1];
                }
                int excl = 0 + prevRow[prev+1];
                currRow[prev+1] = max(incl,excl);
            }
            // shifting
            prevRow = currRow;
        }
        return prevRow[-1+1];
    }

    int solveTabSO2(vector<vector<int>>&cuboids){
        int n = cuboids.size();
        // vector<vector<int> >dp(n+1,vector<int>(n+1,0));
        // vector<int>prevRow(n+1,0);
        vector<int>currRow(n+1,0);
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = -1; prev<=curr-1;prev++){
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
                    incl = cuboids[curr][2] + currRow[curr+1];
                }
                int excl = 0 + currRow[prev+1];
                currRow[prev+1] = max(incl,excl);
            }
            // shifting
            // prevRow = currRow; 
        }
        return currRow[-1+1];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // sorting individual cuboid, to get height at 2nd index[largest]
        for(auto &cuboid: cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        // sorting all cuboids
        sort(cuboids.begin(), cuboids.end()); //0 based sorting;      //1 based sorting: done in mega class
        int curr = 0;
        int prev = -1;
        // int ans = solveRec(cuboids,curr,prev);

        int n = cuboids.size();
        vector<vector<int> >dp(n+1,vector<int>(n+1,-1));
        // int ans = solveMem(cuboids,curr,prev,dp);
        // int ans = solveTab(cuboids);
        // int ans = solveTabSO(cuboids);
        int ans = solveTabSO2(cuboids);
        return ans;
    }
};
