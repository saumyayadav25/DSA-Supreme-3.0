#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int> >adjList;

    void addEdge(int u, int v, bool direction){
        // direction:0-> undirected graph(assumed, can take opposite also)
        // direction:1-> directed graph
        if(direction==0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{
            // directed edge
            adjList[u].push_back(v);
        }
    }

    void printAdjList(int n){
        for(int i = 0; i<n;i++){
            cout << i << ": ";
            cout << "{";
            list<int> temp = adjList[i];
            for(auto j:temp){
                cout << j<<",";
            }
            cout << "}" << endl;
        }
        // for(auto i: adjList){
        //     cout << i.first << ": "; //key
        //     cout << "{";
        //     for(auto j: i.second){ //value
        //         cout << j << ", ";
        //     }
        //     cout << "}" << endl;
        // }
    }

};

int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    int n = 4;
    g.printAdjList(n);
    return 0;
}



// gfg "Print adjacency list" solution
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>>ans(V);
        for(auto edge: edges){
            int u = edge.first;
            int v = edge.second;
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        return ans;
    }
};
