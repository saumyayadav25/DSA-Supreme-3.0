// leetcode 55. Jump Game

class Solution {
public:
    bool solve(vector<int>& nums, int i){
        // base case
        if(i == nums.size()-1) return true;
        if(i >= nums.size()) return false;
        // if(nums[i] == 0) return false;   //stuck at that index

        bool recAns = false;
        for(int jump = 1;jump <= nums[i];jump++){
            recAns = recAns || solve(nums, i+jump);
        }
        return recAns;
    }
    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
};