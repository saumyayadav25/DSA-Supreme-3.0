// leetcode 983. Minimum Cost For Tickets

class Solution {
public:
    int mincostTickets_helper(vector<int>& days, vector<int>& costs, int i){
        // base case
        if(i>=days.size()) return 0;
        // 1case
        // 1 Day Pass taken
        int cost1 = costs[0] + mincostTickets_helper(days, costs, i+1);
        // 7 Day Pass taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j<days.size() && days[j]<=passEndDay){
            j++;
        }
        int cost7 = costs[1] + mincostTickets_helper(days,costs,j);
        // 30 Day Pass taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j<days.size() && days[j]<=passEndDay){
            j++;
        }
        int cost30 = costs[2] + mincostTickets_helper(days,costs,j);
        return min(cost1,min(cost7,cost30));
    }

    int minCostTickets_Mem(vector<int>& days, vector<int>& costs, int i, vector<int>&dp){
        // base case
        if(i>=days.size()) return 0;
        if(dp[i] != -1) return dp[i];
        // 1 Day Pass taken
        int cost1 = costs[0] + minCostTickets_Mem(days, costs, i+1,dp);
        // 7 Day Pass taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j<days.size() && days[j]<=passEndDay){
            j++;
        }
        int cost7 = costs[1] + minCostTickets_Mem(days,costs,j,dp);
        // 30 Day Pass taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j<days.size() && days[j]<=passEndDay){
            j++;
        }
        int cost30 = costs[2] + minCostTickets_Mem(days,costs,j,dp);
        dp[i] = min(cost1,min(cost7,cost30));
        return dp[i];
    }

    // TC:O(N^2)
    // SC:O(N)
    int minCostTickets_Tab(vector<int>& days, vector<int>& costs, int i){
        vector<int>dp(days.size()+1,-1);
        dp[days.size()] = 0;

        for(int i = days.size()-1; i>=0; i--){
            // 1 Day Pass taken
            int cost1 = costs[0] + dp[i+1];
            // 7 Day Pass taken
            int passEndDay = days[i] + 7 - 1;
            int j = i;
            while(j<days.size() && days[j]<=passEndDay){
                j++;
            }
            int cost7 = costs[1] + dp[j];
            // 30 Day Pass taken
            passEndDay = days[i] + 30 - 1;
            j = i;
            while(j<days.size() && days[j]<=passEndDay){
                j++;
            }
            int cost30 = costs[2] + dp[j];
            dp[i] = min(cost1,min(cost7,cost30));
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return mincostTickets_helper(days,costs,0);

        // vector<int>dp(days.size()+1,-1);
        // return minCostTickets_Mem(days, costs,0,dp);
        return minCostTickets_Tab(days,costs,0);
    }
};