// gfg: Minimum Cost of Ropes

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        for(int i = 0; i < arr.size(); i++){
            int val = arr[i];
            pq.push(val);
        }
        long long cost = 0;
        while(pq.size()!=1){
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();

            long long sum = first + second;

            cost = cost + sum;

            pq.push(sum);
        }
        return cost;
    }
};