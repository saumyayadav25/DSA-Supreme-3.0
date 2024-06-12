// Leetcode 287: find the duplicate number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Negative marking method
        int ans = -1;
        for(int i=0; i<nums.size();i++){
            int index = abs(nums[i]);
            if(nums[index]<0){
                ans=index;
                break;
            }
                nums[index] *=-1;
        }
        return ans;

        // Positioning method
        while(nums[0] != nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
};