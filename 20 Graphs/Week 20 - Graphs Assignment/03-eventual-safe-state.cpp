// gfg: Eventual Safe States

class Solution {
  public:
  bool checkCyclicDirectedGraphUsingDFS(vector<int>adj[], int src, unordered_map<int,bool> &visited, unordered_map<int,bool>&dfsVisited, int safenodes[]){
    visited[src] = true;
    dfsVisited[src] = true;
    safenodes[src] = 0;
    for(auto nbr: adj[src]){
        if(!visited[nbr]){
            bool aageKaAnswer = checkCyclicDirectedGraphUsingDFS(adj, nbr, visited, dfsVisited, safenodes);
            if(aageKaAnswer == true){
                return true;
            }
        }
        if(visited[nbr] == true && dfsVisited[nbr] == true){
            return true; //cycle present
        }
    }
    // non-cycle path
    dfsVisited[src] = false; //backtrack
    safenodes[src] = 1;
    return false;
  }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_map<int,bool> visited, dfsVisited;
        int safeNodes[V] = {0};
        for(int i = 0; i < V; i++){
            if(!visited[i]) checkCyclicDirectedGraphUsingDFS(adj, i, visited, dfsVisited, safeNodes);
        }
        for(int i = 0; i < V; i++){
            if(safeNodes[i]) ans.push_back(i);
        }
        return ans;
    }
};