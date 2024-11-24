// lc 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
public:
    int Dijkstra(int src, int n, unordered_map<int, list<pair<int, int>>> &adjList, int&distanceThreshold){
        vector<int>dist(n, INT_MAX);
        set<pair<int,int>>st;
        dist[src] = 0;
        st.insert({0,src});
        int reachableCities = 0; // cities atmost having distanceThreshold

        while(!st.empty()){
            auto top = *st.begin();
            st.erase(st.begin());
            int nodeDist = top.first;
            int node = top.second;

            if(node != src && nodeDist <= distanceThreshold){
                reachableCities++;
            }

            // update neighbor dists
            for(auto nbr: adjList[node]){
                int currDist = nodeDist + nbr.second;
                if(currDist < dist[nbr.first]){
                    auto it = st.find({dist[nbr.first], nbr.first});
                    if(it != st.end()){
                        st.erase(it); // remove old entry
                    }
                    dist[nbr.first] = currDist;
                    st.insert({dist[nbr.first], nbr.first});
                }
            }
        }
        return reachableCities;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, list<pair<int, int>>> adjList;
        for(auto edge: edges){
            int &u = edge[0];
            int &v = edge[1];
            int &w = edge[2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        int city = 0;
        int minReachableCities = INT_MAX;
        for(int u = 0; u < n; u++){
            int reachableCitiesCount = Dijkstra(u,n, adjList, distanceThreshold);
            if(reachableCitiesCount <= minReachableCities){
                minReachableCities = reachableCitiesCount;
                city = u;
            }
        }
        return city;
    }
};