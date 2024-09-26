#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    // first int: u,
    // second int: v,
    // third int: wt
    unordered_map<int,list<pair<int,int> > >adjList;

    void addEdge(int u, int v, int weight, bool direction){
        // direction:0-> undirected graph(assumed, can take opposite also)
        // direction:1-> directed graph
        if(direction==0){
            adjList[u].push_back({v,weight});
            adjList[v].push_back({u,weight});
        }
        else{
            // directed edge
            adjList[u].push_back({v,weight});
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
    g.addEdge(0,1,3,1);
    g.addEdge(0,2,4,1);
    g.addEdge(1,2,1,1);
    g.addEdge(2,3,16,1);
    int n = 4;
    g.printAdjList(n);
    return 0;
}