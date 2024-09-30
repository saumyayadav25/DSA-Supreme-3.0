//leetcode 53: maximum subarray
// KADANE ALGORITHM: TC:O(N)
class Solution {
public:
    int kadaneAlgo(vector<int>& nums){
        int ans=INT_MIN;
        int sum=0;
        for(int i=0; i<nums.size();i++){
            int num=nums[i];
            sum+=num;
            ans=max(ans, sum);
            if(sum<0) sum=0;
        }
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        return kadaneAlgo(nums);
    }
};



// BRUTE FORCE: TC:O(N^2)->TLE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n;i++){
            int sum = 0;
            for(int j = i; j<n;j++){
                sum+=nums[j];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
