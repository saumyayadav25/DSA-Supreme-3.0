// leetcode 347. Top K FRequent Elements

// TC: N(logK)
// SC: O(N+K)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // frequency of each element
        unordered_map<int,int> freqMap; //key: element, value: freq
        for(auto num: nums){
            freqMap[num]++;
        }
        // pair<int,int> -> shows {freq, num};
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        // step 3: iterate over the freq map and maintain heap of size k
        for(auto entry: freqMap){
            minHeap.push({entry.second, entry.first}); //heap has pairs now
            if(minHeap.size()>k) minHeap.pop(); // removing the least frequent element
        }

        // at this point, my minHeap has top k freq elements
        vector<int>ans;
        while(!minHeap.empty()){
            // pair<int,int> top = minHeap.top();
            // auto top = minHeap.top(); 
            auto [freq, num] = minHeap.top(); // using destructuring, just another syntax
            minHeap.pop();
            // ans.push_back(top.second);
            ans.push_back(num);
        }
        return ans;
    }
};