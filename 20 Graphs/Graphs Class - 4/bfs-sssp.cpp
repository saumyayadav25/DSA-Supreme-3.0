#include<iostream>
#include<list>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int> > adj;

    void addEdge(int u, int v, bool direction) {
      //direction = 0 -> undirected edge
      //direction = 1 -> directed edge
        if(direction == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else {
            adj[u].push_back(v);
        }
    }

    void printAdjList(int n) {
        for(int i=0; i<n; i++) {
            cout << i <<": {";
            for(auto j: adj[i]) {
            cout << j <<", ";
            }
            cout << "}" << endl;
        }
    }

        // TC:O(V+E)
    void shortestPathBfs(int src, int dest) {
        unordered_map<int,bool> vis;
        unordered_map<int,int> parent;
        queue<int> q;

        //intial state;
        q.push(src);
        vis[src] = true;
        parent[src] = -1;

        //main logic 
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            for(auto nbr: adj[frontNode]) {
                if(!vis[nbr]) {
                q.push(nbr);
                vis[nbr] = true;
                parent[nbr] = frontNode;
                }
            }
        }

        //parent array ready
        vector<int> path;
        int node = dest;
        while(node != -1) {
            path.push_back(node);
            node = parent[node];
        }
        //reverse path
        reverse(path.begin(), path.end());
        //print path
        cout << "Printing Path: " ;
        for(auto i: path) {
            cout << i <<"->" ;
        }cout << endl;
    }

};

int main() {
    Graph g;

    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(2,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,3,0);

    int src = 0;
    int dest = 3;
    g.shortestPathBfs(src,dest);

    return 0;
}
