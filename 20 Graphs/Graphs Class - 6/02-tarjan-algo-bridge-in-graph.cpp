#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

// TC: O(V+e)-> linear TC
class Graph{
    public:
        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v, bool direction){
            // direction 1-> directed edge
            if(direction==1) adj[u].push_back(v);
            else{
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        void printAdjList(int n){
            for(int i = 0; i < n; i++){
                cout << i << "-> {";
                for(auto nbr: adj[i]){
                    cout << nbr << ", ";
                }
                cout << "}" << endl; 
            }
        }

        void countBridges(int src, int parent, vector<int>&tin, vector<int>&low, unordered_map<int,bool>&vis, int timer){
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
                    countBridges(nbr, src, tin, low, vis, timer);
                    // backtrack-> bridge check
                    low[src] = min(low[src], low[nbr]); //can forget this
                    if(low[nbr] > tin[src]){
                        // bridge exist
                        cout << "bridge found: ";
                        cout << nbr << "-" << src << endl;
                    }
                }
                else{
                    // aready visited and not parent node
                    // update low time if possible
                    low[src] = min(low[src], low[nbr]);
                }
            }
        }

};

int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(0,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,4,0);
    int n = 5;
    g.printAdjList(n);
    int timer = 0;
    int src = 0;
    int parent = -1;
    vector<int>tin(n);
    vector<int>low(n);
    unordered_map<int, bool> vis;
    g.countBridges(src, parent, tin, low, vis, timer);
    return 0;
}