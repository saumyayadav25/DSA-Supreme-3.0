// leetcode 1. Two Sum

// TC: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        // for(int i = 0; i < nums.size(); i++){
        //     int val = nums[i];
        //     m[val] = i;
        // }
        // main logic
        for(int i = 0; i < nums.size(); i++){
            int current = nums[i];
            int required = target - current;
            if(m.find(required) != m.end()){
             // if found
                return {i,m[required]};
            }
            m[current] = i;
        }
    return {-1,-1};
    }
};




// another way: better for interview as it shows you know multiple cases you have handled
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int> > map;
        // value to indexes store
        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
            map[val].push_back(i);
        }
        // ab har value ke har possible index ki mapping store karli hai
        for(int i = 0; i < nums.size(); i++){
            int current = nums[i];
            int required = target - nums[i];
            if(map.find(required) != map.end()){
                // found
                // 1 element ko 1 hi baar use krna hai, duplicate element wale case ko bhi handle krna hai
                if(required == current && map[current].size()==1){
                    // iska mtlb mai same element ko 2 baar use kr rha hu
                    // skip iteration
                    continue;
                }
                if(required == current && map[current].size() > 1){
                    // duplicate wala case
                    return {map[current][0], map[current][1]};
                }
                else{
                    // required != current
                    return {i,map[required][0]};
                }
            }
        }
        return {-1,-1};
    }
};