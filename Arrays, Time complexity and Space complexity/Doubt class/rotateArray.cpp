//method-2 of rotate/shift an array: reverse method
//leetcode 189
class Solution{
public:
    void rotate(vector<int>& nums, int k){
        int n=nums.size();
        k=k%n;
        //step 1. reverse all
        reverse(nums.begin(), nums.end());
        //step 2. reverse first k
        reverse(nums.begin(), nums.begin()+k);
        //step 3. reverse first n-k
        reverse(nums.begin()+k, nums.end());
    }
};
