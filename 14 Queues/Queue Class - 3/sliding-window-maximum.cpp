// leetcode 239. Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        // process first window
        for(int i = 0; i < k; i++){
            int element = nums[i];
            // ye element queue ke andar insert hoga hi
            // abhi tk jitni queue bani hui h, check chote elements and pop them
            
            // int dqIndex = dq.front();
            while(!dq.empty() && nums[dq.back()] < element){
                dq.pop_back();
            }
            // insert current element
            dq.push_back(i);
        }
        // get answer for first window
        int index = dq.front();
        int element = nums[index];
        ans.push_back(element);

        // process remaining windows
        for(int i = k; i < nums.size(); i++){
            // removal
            if(!dq.empty() && dq.front() < i-k+1) dq.pop_front();
            // addition
            int element = nums[i];
            while(!dq.empty() && nums[dq.back()] < element){
                dq.pop_back();
            }
            dq.push_back(i);
            // ans store
            int index = dq.front();
            int ansElement = nums[index];
            ans.push_back(ansElement);
        }
        return ans;
    }
};