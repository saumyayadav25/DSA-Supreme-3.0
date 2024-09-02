// leetcode 215. Kth largest element in an array

// using min heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min heap
        priority_queue<int, vector<int>, greater<int> > pq;
        // initial state maintain -> insert first k elements
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        // process remaning elements
        // we want ki heap ke end me, k large element ho, taaki top me kth largest mil jaye
        // k large element rkhne ke liye we will make sure ki hum bas large element hi insert krein
        for(int i = k; i < nums.size(); i++){
            int element = nums[i];
            if(element>pq.top()){
                pq.pop();
                pq.push(element);
            }
        }
        int ans = pq.top();
        return ans;
    }
};


// using max heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // max heap
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
            pq.push(val);
        }
        int ans = -1;
        while(k != 0){
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};


