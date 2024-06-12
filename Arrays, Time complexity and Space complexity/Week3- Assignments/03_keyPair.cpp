//METHOD WITH TIME COMPLEXITY O(N^2) and SPACE COMLEXITY O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] + nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// ANOTHER METHOD: TWO POINTER APPROACH: but sorting not helpful in this case, as u have to return index,
// by sorting, index will be changed
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int l=0;
        int h=n-1;
        while(l<h){
            int csum = nums[l] + nums[h];
            if(csum == target){
                ans.push_back(l);
                ans.push_back(h);
                return ans;
            }
            else if(csum>target) h--;
            else l++;
        }
        return ans;
    }
};