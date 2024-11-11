// lc 239. Sliding Window Maximum


// TC: O(NlogN) -> logN: push in heap
// SC: O(N) if k==n in worst case
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // pair <val, index> : sorted value-wise
        vector<int>ans;
        
        // consider first window
        for(int i = 0; i < k; i++){
            pq.push({nums[i],i});
        }
        // store max of first window
        ans.push_back(pq.top().first);

        // consider rest of windows
        for(int i = k; i < nums.size(); i++){
            pq.push({nums[i],i});
            // remove if max are from previous windows
            while(pq.top().second <= i - k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};