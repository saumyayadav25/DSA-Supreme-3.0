#include<iostream>
#include<unordered_map>
#include<set>
#include<list>
#include<vector>
#include<limits.h>
using namespace std;

// SIR KA CODE SEE
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

    // TC:O(N^3)
    void floydWarshalAlgo(int n){
        vector<vector<int>>dist(n,vector<int>(n,1e9));

        // step1: diagonal par 0 
        for(int i = 0; i<n;i++){
            dist[i][i] = 0;
        }
        // step2: copy all distance from graph to matrix
        for(auto a: adjList){
            for(auto b: a.second){
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                dist[u][v] = wt;
            }
        }
        // main logic
        for(int helper = 0; helper < n; helper++){
            for(int src = 0; src < n; src++){
                for(int dest = 0; dest < n; dest++){
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }
        cout <<"printing result of FW algo: "<<endl;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                cout << dist[i][j]<<", ";
            }
            cout <<endl;
        }
    }
};


int main(){
    Graph g;

    g.addEdge(0,2,-2,0);
    g.addEdge(1,0,4,0);
    g.addEdge(1,2,3,0);
    g.addEdge(3,1,-1,0);
    g.addEdge(2,3,2,0);

    g.floydWarshalAlgo(4);

    return 0;
}