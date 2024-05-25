//single number( alternative approach of XOR method)
//leetcode
class Solution{
public:
    int sigleNumber(vector<int>& nums){
        //sorting
        sort(nums.begin(), nums.end()); 
        int n=nums.size();
        int ans=-1;
        int i=0;
        while(i < n){
            if(i + 1 < n && nums[i]==nums[i+1]){
                i +=2;
            }
            else{
                ans =nums[i];
                break;
            }
        }
        return ans;
    }
};
