// leetcode 134. Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int balance = 0;
        int deficit = 0;
        for(int i = 0; i<gas.size(); i++){
            balance = balance + gas[i] - cost[i];
            // +ve -> balanced hai.
            // -ve -> tells deficit
            if(balance < 0){
                deficit += abs(balance);
                // deficit aya hai mtlb aage nhi ja paye, start update hoga
                start = i + 1;
                balance = 0;
            }
        }
        if(balance - deficit >= 0) return start;
        else return -1;
    }
};