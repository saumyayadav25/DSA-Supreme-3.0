#include<iostream>
#include<unordered_map>
#include<set>
#include<list>
#include<vector>
#include<limits.h>
using namespace std;

class Graph{
    public:
    // first int: u,
    // second int: v,
    // third int: wt
    unordered_map<int,list<pair<int,int> > >adjList;

    void addEdge(int u, int v, int weight, bool direction){
        // direction:1-> undirected graph(assumed, can take opposite also)
        // direction:0-> directed graph
        adjList[u].push_back({v,weight});
        if(direction==1){
            adjList[v].push_back({u,weight});
        }
    }

    void printAdjList(int n){
        for(int i = 0; i<n;i++){
            cout << i << ": ";
            cout << "{";
            list<pair<int,int> > temp = adjList[i];
            for(auto j:temp){
                // j is a pair here
                cout << "("<<j.first<<","<<j.second<<")";
            }
            cout << "}" << endl;
        }
    }

    // TC:O(V*E)
    void bellManFordAlgo(int src, int n){
        vector<int> dist(n, INT_MAX);
        // initial state
        dist[src] = 0;
        // n-1 times loop chalao
        for(int i = 0; i < n - 1; i++){
            // har edge par jao and relaxation step karo
            for(auto a: adjList){
                for(auto b: a.second){
                    // a-> pair<int,list<pair<int,int> > >
                    // a.first = u
                    // a.second ->  nbr of u node->  list <pair<int,int>>
                    // b-> pair<int,int>
                    // b.first->v;    b.second->weight
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }
        bool negativeCyclePresent = false;
        for(auto a: adjList){
            for(auto b: a.second){
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    negativeCyclePresent = true;
                    break;
                }
            }
        }
        if(negativeCyclePresent) cout << "Negative cycle present"<<endl;
        else{
            cout << "printing bellman ford result: " << endl;
            for(int i=0; i<n; i++) {
                cout << dist[i] << " ";
            }
        }
    }

};


int main(){
    Graph g;

    // g.addEdge(0,1,-1,0);
	// g.addEdge(1,4,2,0);
	// g.addEdge(0,2,4,0);
	// g.addEdge(3,2,5,0);
	// g.addEdge(4,3,-3,0);
	// g.addEdge(1,2,3,0);
	// g.addEdge(1,3,2,0);
	// g.addEdge(3,1,1,0);

    // -ve cycle case
    g.addEdge(0,1,-1,0);
    g.addEdge(1,0,-2,0);

    g.bellManFordAlgo(0,2);
    return 0;
}