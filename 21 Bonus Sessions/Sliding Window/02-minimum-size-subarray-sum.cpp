// leetcode 209. Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;
        int e = 0;
        int sum = 0;
        int len = INT_MAX;

        while(e < nums.size()){
            sum = sum + nums[e];
            // ho skta hai ye sum < target ho, ya fir >= target ho
            while(sum>=target){ // minimise
                // sabse phle-> if you have a valid ans then store it
                len = min(len, e-s+1);
                // minimise-> sum decrease hoga jaha bhi start hai uss number se
                sum = sum - nums[s];
                s++;
            }
            // reached here means: sum<target
            // expand
            e++;
        }

        if(len == INT_MAX){
            return 0;
        }
        else{
            return len;
        }
    }
};