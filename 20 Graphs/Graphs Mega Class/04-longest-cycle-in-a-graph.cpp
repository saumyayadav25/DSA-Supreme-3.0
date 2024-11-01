// leetcode 2360. Longest Cycle in a Graph

class Solution{
public:
    void dfs(int node, vector<int> &edges, vector<bool> &visited, vector<bool> &dfsTracker, vector<int> &dist, int currLength, int &longestCycleLength){
        if (node == -1) return;
        visited[node] = true;
        dfsTracker[node] = true;
        dist[node] = currLength;

        int nextNode = edges[node];

        if (nextNode != -1){
            if(!visited[nextNode]){
                dfs(nextNode, edges, visited, dfsTracker, dist, currLength + 1, longestCycleLength);
            }
            else if(dfsTracker[nextNode]){
                // cycle is there.
                int cycleLength = currLength - dist[nextNode] + 1;
                longestCycleLength = max(longestCycleLength, cycleLength);
            }
        }
        dfsTracker[node] = false;
    }

    int longestCycle(vector<int> &edges){
        int n = edges.size();
        vector<bool> visited(n, 0);
        vector<bool> dfsTracker(n, 0);
        vector<int> dist(n, 0); // we will record distances
        int longestCycleLength = -1;

        for (int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, edges, visited, dfsTracker, dist, 0, longestCycleLength);
            }
        }
        return longestCycleLength;
    }
};





// BFS topo
class Solution{
public:
    int longestCycle(vector<int> &edges){
        int n = edges.size();
        vector<int> inDegree(n, 0);

        // Step 1: Compute in-degrees
        for (int i = 0; i < n; ++i){
            if (edges[i] != -1){
                inDegree[edges[i]]++;
            }
        }

        // Step 2: Kahn's Algorithm to remove acyclic nodes
        queue<int> q;
        for (int i = 0; i < n; ++i){
            if (inDegree[i] == 0){
                q.push(i);
            }
        }

        // Remove nodes with in-degree zero iteratively
        while (!q.empty()){
            int u = q.front();
            q.pop();
            int v = edges[u];
            if (v != -1){
                inDegree[v]--;
                if (inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        // Step 3 and 4: Find cycles and compute their lengths
        vector<bool> visited(n, false);
        int ans = -1;

        for (int i = 0; i < n; ++i){
            if (inDegree[i] > 0 && !visited[i]){
                int current = i;
                int cycleLength = 0;
                while (!visited[current]){
                    visited[current] = true;
                    current = edges[current];
                    cycleLength++;
                }
                ans = max(ans, cycleLength);
            }
        }
        return ans;
    }
};