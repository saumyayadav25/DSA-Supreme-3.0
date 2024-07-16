// leetcode 724: find pivot index
class Solution {
public:
    int bruteForce(vector<int>& nums){
        for(int i=0; i<nums.size();i++){
            int lsum=0;
            int rsum=0;
            //find lsum excluding current index
            for(int j=0; j<i;j++){
                lsum +=nums[j];
            }
            //find rsum excluding current index
            for(int j=i+1; j<nums.size();j++){
                rsum +=nums[j];
            }
            if(lsum==rsum) return i;
        }
        return -1;
    }
    int prefixSumApproach(vector<int>&nums){
        vector<int>lsum(nums.size(),0);
        vector<int>rsum(nums.size(),0);

        for(int i=1; i<nums.size();i++){
            lsum[i]=lsum[i-1]+nums[i-1];
        }
        for(int i=nums.size()-2; i>=0;i--){
            rsum[i]=rsum[i+1]+nums[i+1];
        }

        for(int i=0; i<nums.size();i++){
            if(lsum[i]==rsum[i]) return i;
        }
        return -1;
    }
    int pivotIndex(vector<int>& nums) {
        // return bruteForce(nums);
        return prefixSumApproach(nums);
    }
};