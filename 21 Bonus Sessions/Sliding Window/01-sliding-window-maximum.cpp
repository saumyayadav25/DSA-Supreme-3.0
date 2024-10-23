// leetcode 239. Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        // first window ko hum process krenge
        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            // current element ko include karo
            dq.push_back(i);
        }

        // store ans
        ans.push_back(nums[dq.front()]);
        // remaining window process
        for(int i = k; i < nums.size(); i++){
            // removal
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            // addition
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            // current element ko include karo
            dq.push_back(i);
            // ans store
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};