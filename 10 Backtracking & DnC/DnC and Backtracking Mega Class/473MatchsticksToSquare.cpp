// leetcode 473: Matchsticks to Square
class Solution {
public:
    bool solve(vector<int>&matchsticks, vector<int>& sides, int i){
        // base case
        // if all sids become zero, it means we have found 4 equal subsets
        if(i==matchsticks.size()) //all matchsticks have been tried
            return sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0;
        
        bool ans = false;
        // ith matchstick can a part of A/B/C/D
        for(int j= 0; j<sides.size();j++){
            if(matchsticks[i]<=sides[j]){
                sides[j]-=matchsticks[i]; //include
                ans = ans || solve(matchsticks, sides, i+1);
                if(ans == true) return true;
                sides[j] += matchsticks[i];
            }
            
        }
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        auto sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
        if(sum % 4 != 0) return false;
        int sideSum = sum / 4 ; 
        vector<int>sides(4, sideSum);  //0-> A side ka sum, 1-> B side ka sum,....
        //sort in decreasing order to escape extra Recursive calls
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks,sides, 0);
    }
};