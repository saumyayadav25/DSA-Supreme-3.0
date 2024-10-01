// gfg: Topological sort 

// TC:O(V+E)
// dfs
class Solution{
	public:
    void topoDFS(int src, unordered_map<int,bool>& vis, vector<int>adj[], vector<int>&ans){
        vis[src] = true;
        for(auto nbr: adj[src]){
            if(!vis[nbr]){
                topoDFS(nbr,vis,adj,ans);
            }
        }
        // backtrack
        ans.push_back(src);
    }

	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    unordered_map<int,bool>visited;
        int n = V;
        vector<int>ans; //can do in stack also
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                topoDFS(i,visited,adj,ans);
            }
        }
        // reverse the ordering
        reverse(ans.begin(),ans.end()); // no need to reverse if using stack
        return ans;
	}
};




// bfs
class Solution{
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

	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int>ans;
        topoBFS(V,adj,ans);
        return ans;
	}
};
