// gfg: Directed Graph Cycle


// topological sort
class Solution {
  public:
    void topoBFS(int n, vector<int>adj[], vector<int>&ans){
        unordered_map<int,int>indegree;
        queue<int> q;

        // prepare indegree map
        for(int src = 0; src < n; src++){
            for(auto nbr: adj[src]){
                // src->nbr
                indegree[nbr]++;
            }
        }

        // check for indegree 0 and push in q
        // maintain initial state in q
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        // main logic
        while(!q.empty()){
            int frontNode = q.front();
            ans.push_back(frontNode);
            q.pop();

            // kyuki frontNode graph se hatt chuki hai
            // update the indegree of its children accordinly
            for(auto nbr: adj[frontNode]){
                // remove frontNode->nbr
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>ans;
        topoBFS(V,adj,ans);

        if(ans.size() == V){
            // all nodes reached-> no cycle
            return false;
        }
        else{
            // cycle present
            return true;
        }
    }
};
