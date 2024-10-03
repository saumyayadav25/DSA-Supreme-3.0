// leetcode 1691. Maximum Height by Stacking Cuboids 


// 1 based indexing solution
class Solution {
public:
    static bool compare(const vector<int>&a, const vector<int>&b){
        if(a[1]==b[1]){
            // if the second element are same, compare first
            if(a[0]==b[0]){
                return a[2]< b[2];
            }
            return a[0]<b[0];
        }
        return a[1] < b[1];
    }

    bool isSafe(vector<int>c1, vector<int>c2){
        return (c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2]);
    }

    int solveRec(vector<vector<int>>& cuboids, int i, int prev){
        if(i==cuboids.size()) return 0;
        int incl = 0;
        // making cuboid from upside
        if(prev==-1 || isSafe(cuboids[prev], cuboids[i])){
            incl = cuboids[i][2] + solveRec(cuboids, i+1, i);
        }
        int excl = solveRec(cuboids,i+1,prev);
        return max(incl,excl);
    }

    int solveMem(vector<vector<int>>& cuboids, int i, int prev,vector<vector<int>>&dp){
        if(i==cuboids.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int incl = 0;
        // making cuboid from upside
        if(prev==-1 || isSafe(cuboids[prev], cuboids[i])){
            incl = cuboids[i][2] + solveMem(cuboids, i+1, i,dp);
        }
        int excl = solveMem(cuboids,i+1,prev,dp);
        return dp[i][prev+1] = max(incl,excl);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // be greedy and take max dimension as height for each cube
        for(auto& cuboid: cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        // 1st based indexing se sort
        sort(cuboids.begin(),cuboids.end(),compare);

        // return solveRec(cuboids,0, -1);
        vector<vector<int>>dp(cuboids.size()+1, vector<int>(cuboids.size()+1,-1));
        return solveMem(cuboids,0, -1,dp);
    }
};