// leetcode 787. Cheapest Flights Within K Stops

class Solution{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k){
        // make Adj list
        unordered_map<int, list<pair<int, int>>> graph;
        for (auto &flight : flights){
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        // minHeap / Priority Queue to select the next city with minimal cost
        // each element would be: {cost so far, current city, stops so far} 
        // considering stops-> use modified dijkstra
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        // WITHOUT visited array-> getting TLE: visited array gives optimised solution
        // visited array storing minimum number of stops to reach a city
        vector<int> visited(n, INT_MAX);
        visited[src] = 0;

        while (!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0];  // total cost so far
            int city = curr[1];  // current city
            int stops = curr[2]; // number of stops made so far

            if (city == dst) return cost;

            // if stops exceeds k, then skip this path
            if (stops > k) continue;

            // if we have already visited the city with fewer stops, skip this path
            if(visited[city] != INT_MAX && visited[city] < stops){
                continue;
            }

            // update the minimum stops for the current city
            visited[city] = min(visited[city], stops);

            // Explore all neighbours cities
            for (auto &nbr : graph[city]){
                int nextCity = nbr.first;
                int price = nbr.second;
                pq.push({cost + price, nextCity, stops + 1});
            }
        }
        return -1;
    }
};