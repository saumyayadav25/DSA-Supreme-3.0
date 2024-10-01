// gfg: Undirected Graph Cycle

// using BFS
class Solution {
  public:
    bool cycleDetectionUndirectedBFS(int src,unordered_map<int,bool>&visited,vector<int> adjList[]){
        queue<int>q;
        unordered_map<int,int>parent;
        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        // main logic
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto nbr: adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                // cycle detection
                else if(visited[nbr] == true && nbr != parent[frontNode]){
                    // cycle present
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        bool ans = false;
            unordered_map<int,bool>visited;
            int n = V;
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    ans = cycleDetectionUndirectedBFS(i,visited,adj);
                    if(ans == true){
                        break;
                    }
                }
            }
            return ans;
    }
};





// using DFS
class Solution {
  public:
    bool checkCycleDFSHelper(int src, unordered_map<int,bool>&vis, vector<int>adj[], int parent){
        vis[src] = true;
        
        for(auto nbr: adj[src]){
            if(!vis[nbr]){
                bool ans = checkCycleDFSHelper(nbr,vis,adj,src);
                if(ans == true) return true;
            }
            else if(vis[nbr] == true && nbr!=parent){
                return true;
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Handle disconnected components
        int n = V;
        int ans = false;
        unordered_map<int,bool>visited;
        int parent = -1;
        for(int i = 0; i<V;i++){
            if(!visited[i]){
                ans = checkCycleDFSHelper(i,visited,adj,parent);
                if(ans) break;
            }
        }
        return ans;
    }
};
