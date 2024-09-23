// leetcode 354. Russian Doll Envelopes

class Solution {
public:
    bool isSafeToPlace(vector<int>e1, vector<int>e2){
        if(e1[0] < e2[0] && e1[1] < e2[1]) return true;
        else return false;
    }

    int solve(vector<vector<int>>&env, int prev, int i){
        if(i == env.size()) return 0;
        int include = INT_MIN;
        if(prev == -1 || env[prev][0] < env[i][0] && env[prev][1] < env[i][1]){
            include = 1 + solve(env, i, i+1);
        }
        int exclude = solve(env, prev, i+1);
        return max(include,exclude);
    }

    int solveMem(vector<vector<int>>&env, int prev, int i, vector<vector<int>>&dp){
        if(i == env.size()) return 0;
        if(dp[prev+1][i] != -1) return dp[prev+1][i];
        int include = INT_MIN;
        if(prev == -1 || env[prev][0] < env[i][0] && env[prev][1] < env[i][1]){
            include = 1 + solveMem(env, i, i+1,dp);
        }
        int exclude = solveMem(env, prev, i+1,dp);
        return dp[prev+1][i] = max(include,exclude);
    }

    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int solveBinary(vector<vector<int>>&env){
        // sorting envelopes in inc order by width and if wi=wj then dec order by height
        sort(env.begin(),env.end(),comp);
        
        // run LIS on height
        if(env.size() == 0) return 0;
        vector<int> ans;
        ans.push_back(env[0][1]);

        for(int i = 1; i < env.size(); i++){
            if(env[i][1] > ans.back()){
                // include
                ans.push_back(env[i][1]);
            }
            else{
                // overwrite
                // find index of just bada element
                int index = lower_bound(ans.begin(),ans.end(),env[i][1])-ans.begin();
                ans[index] = env[i][1];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // individual envelope ko sort krne ki need nhi hai: ques ne mana kia hai rotate krne se
        // can sort entire array
        // sort(envelopes.begin(),envelopes.end());
        // int ans = solve(envelopes,-1,0);

        // vector<vector<int>>dp(envelopes.size()+1, vector<int>(envelopes.size()+1,-1));
        // int ans = solveMem(envelopes,-1,0,dp);

        int ans = solveBinary(envelopes);
        return ans;
    }
};