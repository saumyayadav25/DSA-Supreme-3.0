// leetcode 983: Minimum Cost For Tickets

class Solution {
public:
    int mincostTickets_helper(vector<int>& days, vector<int>& costs, int i){
        // base
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

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return mincostTickets_helper(days,costs,0);
    }
};