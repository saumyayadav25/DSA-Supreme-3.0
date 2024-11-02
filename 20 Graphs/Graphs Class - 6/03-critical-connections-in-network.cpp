// leetcode 1192. Critical Connections in a Network

class Solution {
public:
    void countBridges(int src, int parent, vector<int>& tin, vector<int>& low, unordered_map<int,bool>& vis, int timer,vector<vector<int> >& ans, unordered_map<int,list<int> >& adj){
            timer++;
            vis[src] = true;
            tin[src] = timer;
            low[src] = timer;

            // traverse on neighbours
            for(auto nbr: adj[src]){
                // because it is undirected graph, toh neighbour me parent bhi ho skta hai
                if(nbr == parent){
                    continue;
                }
                else if(!vis[nbr]){
                    // normal traversal and check for bridges
                    countBridges(nbr, src, tin, low, vis, timer,ans,adj);
                    // backtrack-> bridge check
                    low[src] = min(low[src], low[nbr]); //can forget this
                    if(low[nbr] > tin[src]){
                        // bridge exists
                        vector<int> temp;
                        temp.push_back(src);
                        temp.push_back(nbr);
                        ans.push_back(temp);
                    }
                }
                else{
                    // aready visited and not parent node
                    // update low time if possible
                    low[src] = min(low[src], low[nbr]);
                }
            }
        }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;
        int timer = 0;
        int src = 0;
        int parent = -1;
        vector<int> tin(n);
        vector<int> low(n);
        unordered_map<int,bool> vis;
        // create adjList
        unordered_map<int, list<int> >adj;
        for(auto i: connections){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        countBridges(src,parent,tin,low,vis,timer,ans,adj); 
        return ans;
    }
};
