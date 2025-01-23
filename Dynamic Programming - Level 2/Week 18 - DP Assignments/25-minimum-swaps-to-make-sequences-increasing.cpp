// leetcode 801. Minimum Swaps To Make Sequences Increasing

class Solution {
public:
    int solve(vector<int>&nums1, vector<int>&nums2, int i, int p1, int p2){
        if(i == nums1.size()) return 0;
        int swap = INT_MAX, noswap = INT_MAX;
        // swap condition
        if(p1 < nums2[i] && p2 < nums1[i]) swap = 1 + solve(nums1, nums2, i + 1, nums2[i], nums1[i]);
        // no swap
        if(p1 < nums1[i] && p2 < nums2[i]) noswap = solve(nums1, nums2, i + 1, nums1[i], nums2[i]);
        return min(swap, noswap);
    }

    int solveTD(vector<int>&nums1, vector<int>&nums2, int i, int p1, int p2, vector<vector<int>>&dp, int isswap){
        if(i == nums1.size()) return 0;
        if(dp[i][isswap] != -1) return dp[i][isswap];
        int swap = INT_MAX, noswap = INT_MAX;
        // swap condition
        if(p1 < nums2[i] && p2 < nums1[i]) swap = 1 + solveTD(nums1, nums2, i + 1, nums2[i], nums1[i], dp, 1);
        // no swap
        if(p1 < nums1[i] && p2 < nums2[i]) noswap = solveTD(nums1, nums2, i + 1, nums1[i], nums2[i], dp, 0);
        return dp[i][isswap] = min(swap, noswap);
    }

    int solveBU(vector<int>&nums1, vector<int>&nums2){
        vector<vector<int>>dp(nums1.size() + 1, vector<int>(2,0));
        for(int i = nums1.size() - 1; i >= 1; i--){
            for(int j = 1; j >= 0; j--){
                int p1 = nums1[i - 1];
                int p2 = nums2[i - 1];
                if(j) swap(p1, p2);
                int swap = INT_MAX, noswap = INT_MAX;
                // swap condition
                if(p1 < nums2[i] && p2 < nums1[i]) swap = 1 + dp[i + 1][1];
                // no swap
                if(p1 < nums1[i] && p2 < nums2[i]) noswap = dp[i + 1][0];
                dp[i][j] = min(swap, noswap);
            }
        }
        return dp[1][0];
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // return solve(nums1, nums2, 0, -1, -1);

        // vector<vector<int>>dp(nums1.size(), vector<int>(2,-1));
        // return solveTD(nums1, nums2, 0, -1, -1, dp, 0);

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solveBU(nums1, nums2);
    }
};