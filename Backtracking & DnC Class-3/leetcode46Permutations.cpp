// leetcode 46: Permutations
class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int> > &ans){
        //base case
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        //permutation-> ith place par sabko chance dena h
        for(int j=i; j<nums.size();j++){
            swap(nums[i], nums[j]);
            solve(nums,i+1,ans);
            //backtrack
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        int i=0;
        solve(nums, i, ans);
        return ans;
    }
};