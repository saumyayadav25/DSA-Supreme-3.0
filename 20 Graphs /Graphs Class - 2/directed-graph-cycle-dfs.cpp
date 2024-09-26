// gfg: Directed Graph Cycle

class Solution {
  public:
    bool DFSHelper(int node, unordered_map<int,bool>&vis, vector<int>adj[],unordered_map<int,bool>&dfsTracker){
        vis[node] = true;
        dfsTracker[node] = true;

        for(auto nbr: adj[node]){
            if(!vis[nbr]){
                bool ans = DFSHelper(nbr,vis,adj,dfsTracker);
                if(ans==true) return true;
            }
            else if(vis[nbr] == true && dfsTracker[nbr] == true){
                // cycle present
                return true;
            }
        }
        // backtrack
        dfsTracker[node] = false;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        bool ans = false;
        int n = V;
        unordered_map<int,bool>vis;
        unordered_map<int,bool>dfsTracker;
        for(int i = 0; i<n;i++){
            if(!vis[i]){
                ans = DFSHelper(i,vis,adj,dfsTracker);
                if(ans == true) break;
            }
        }
        return ans;
    }
};