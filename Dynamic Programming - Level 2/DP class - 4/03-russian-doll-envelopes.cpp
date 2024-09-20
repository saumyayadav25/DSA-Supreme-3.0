// leetcode 354. Russian Doll Envelopes
// (TLE)
class Solution {
public:
    bool isSafeToPlace(vector<int>e1, vector<int>e2){
        if(e1[0] < e2[0] && e1[1] < e2[1]) return true;
        else return false;
    }

    int solveTabSO2(vector<vector<int>>&cuboids){
        int n = cuboids.size();
        vector<int>currRow(n+1,0);
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = -1; prev<=curr-1;prev++){
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev],cuboids[curr])){
                    incl = 1 + currRow[curr+1];
                }
                int excl = 0 + currRow[prev+1];
                currRow[prev+1] = max(incl,excl);
            }
        }
        return currRow[-1+1];
    }

    int maxEnvelopes(vector<vector<int>>& cuboids) {
        // individual envelope ko sort krne ki need nhi hai: ques ne mana kia hai rotate krne se
        // can sort entire array
        sort(cuboids.begin(),cuboids.end());
        int ans = solveTabSO2(cuboids);
        return ans;
    }
};
