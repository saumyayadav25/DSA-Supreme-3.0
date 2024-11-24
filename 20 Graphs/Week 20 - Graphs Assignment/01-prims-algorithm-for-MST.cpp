// gfg: Minimum Spanning Tree

// PRIM'S ALGORITHM
// TC: O(N^2)
class Solution{
	public:
    int getMinValueNode(vector<int>&key, vector<int>&mst){
        int temp = INT_MAX;
        int index = -1; // represent actual node having min value
        for(int i = 0; i < key.size(); i++){
            if(key[i] < temp && mst[i] == false){
                temp = key[i];
                index = i;
            }
        }
        return index;
    }

	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<int>key(V,INT_MAX);
        vector<int>mst(V,false); // to keep track which all nodes are added into mst
        vector<int>parent(V, -1); // stores final mst relation
        key[0] = 0;

        while(true){
            // step 1: find u
            int u = getMinValueNode(key,mst);
            if(u == -1){
                break;
            }
            // step 2: mark mst[u] as true
            mst[u] = true;

            // step 3: process all adj nodes to u
            for(auto edge: adj[u]){
                int v = edge[0];
                int w = edge[1];
                if(mst[v] == false && w < key[v]){
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        // finding sum of w's of the edges of MST
        int sum = 0;
        for(int u = 0; u < parent.size(); u++){
            if(parent[u] == -1) continue;
            for(auto edge: adj[u]){
                int v = edge[0];
                int w = edge[1];
                if(v == parent[u]){
                    sum += w;
                }
            }
        }
        return sum;
    }
};