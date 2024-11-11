// lc 2163. Minimum Difference in Sums After Removal of Elements

// TC: O(NlogN) -> logN time to push into q
// SC: O(N)
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long>prefix(nums.size(),-1); //prefix[i] = sum of first n elements from left side
        vector<long long>suffix(nums.size(),-1); //suffix[i] = sum of first n elements from right side

        long long sum = 0; //minimum n elements sum
        priority_queue<long long>pq; //max heap
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            pq.push(nums[i]);

            // pop out max elements
            if(pq.size() > n){
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == n){
                prefix[i] = sum;
            }
        }

        sum = 0; // max n elements sum
        priority_queue<long long, vector<long long>, greater<long long >>pq2; //min heap
        for(int i = nums.size() - 1; i >= 0; i--){
            sum += nums[i];
            pq2.push(nums[i]);

            // pop out max elements
            if(pq2.size() > n){
                sum -= pq2.top();
                pq2.pop();
            }

            if(pq2.size() == n){
                suffix[i] = sum;
            }
        }

        long long ans = LONG_LONG_MAX;
        for(int i = n - 1; i < 2*n ; i++){
            ans = min(ans, prefix[i] - suffix[i+1]);
        }
        return ans;
    }
};