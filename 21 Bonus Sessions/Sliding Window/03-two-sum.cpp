// leetcode 1. Two Sum

// TC: O(NlogN)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > data;
        for(int i = 0; i < nums.size(); i++){
            int index = i;
            int val = nums[i];
            data.push_back({val,index});
        }
        // now vector is ready
        // sorting kardo
        sort(data.begin(), data.end());

        // now apply 2 pointer approach
        int s = 0;
        int e = nums.size() - 1;
        while(s<e){
            int sum = data[s].first + data[e].first;
            if(sum == target){
                vector<int>temp;
                temp.push_back(data[s].second);
                temp.push_back(data[e].second);
                return temp;
            }
            if(sum > target){
                e--;
            }
            else{
                s++;
            }
        }
        vector<int>temp;
        return temp;
    }
};