// leetcode 268: missing number
// TC: O(N)-> XOR METHOD
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        // 1. XOR all values of array
        for(int i=0; i<nums.size();i++){
            ans ^= nums[i];
        }
        // 2. XOR all range items [0,N]
        int n=nums.size();
        for(int i=0;i<=n;i++){
            ans ^= i;
        }
        return ans;
    }
};