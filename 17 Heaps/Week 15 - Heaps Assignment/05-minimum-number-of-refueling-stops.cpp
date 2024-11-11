// lc 871. Minimum Number of Refueling Stops

// TC: O(NlogN) -> n fuel stations
// SC: O(N)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int dist = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<pair<int,int>>pq; // {fuel, position}
        while(true){
            while(i < stations.size()){
                // push stations within the reach with my current fuel levels from my current pos
                if(stations[i][0] <= dist + fuel){
                    pq.push({stations[i][1], stations[i][0]});
                }
                else break;
                i++;
            }

            // travel with full fuel level
            dist += fuel;
            fuel = 0;

            // reached
            if(dist >= target) break;
            
            // no fuel stations withing reach
            if(pq.empty()){
                stops = -1;
                break;
            }

            // refuel and re-adjust distance and fuel based on the distance travelled and fuel used till that station
            auto &top = pq.top();
            fuel = (dist - top.second) + top.first;
            dist = top.second;
            pq.pop();
            stops++;
        }
        return stops;
    }
};