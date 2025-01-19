# Graphs Class - 1
Graphs are non-linear data structures that consist of **nodes (vertices)** and **edges**.

#### Graphs can be
- **Directed** and **Undirected** Graphs
- **Weighted** and **Unweighted** Graphs
- **Cyclic** and **Acyclic** Graphs
  
  ![image](https://github.com/user-attachments/assets/9b63d9ed-26fc-4841-9e52-21fe0fddeeef)

### Degree of a Node
- **In-degree:** Number of incoming edges.
- **Out-degree:** Number of outgoing edges.

  
## Graph Implementation
Graphs can be implemented using:
1. **Adjacency Matrix**
2. **Adjacency List**

#### Adjacency Matrix
Representation: A 2D array where `mat[i][j] = 1` if there's an edge between node `i` and node `j`.
  
![image](https://github.com/user-attachments/assets/5c0d92b2-b403-4693-b368-5c4ec4372b79)

```
void addEdge(vector<vector<int>> &mat, int i, int j){
    mat[i][j] = 1;
    mat[j][i] = 1; // undirected
}
```
Time Complexity: O(V²)

Space Complexity: O(V²), where V is the number of vertices.

### Adjacency List
Representation: A hash map (`unordered_map`) where the key is the node, and the value is a list of its neighbors.

<img width="625" alt="Screenshot 2025-01-16 at 12 54 25 PM" src="https://github.com/user-attachments/assets/6611762b-6d94-4b36-8cac-e4b6d9f69bd7" />

<img width="631" alt="Screenshot 2025-01-16 at 1 00 42 PM" src="https://github.com/user-attachments/assets/c9eef1c1-818f-4bd4-a654-5b8fff80a138" />


```
unordered_map<int, list<int>> adjList; // Unweighted graph

unordered_map<int, list<pair<int, int>>> adjList; // Weighted graph
```

Time Complexity: O(V + E)

Space Complexity: O(V + E), where E is the number of edges.


# Breadth First Search Traversal (BFS Traversal)
- Traversal technique where vertices are visited level by level using a queue.  

- To avoid visiting a node more than once, we use a **boolean visited array**.  

### BFS Algorithm  

1. Initialize a queue and enqueue the starting/source node. 
2. Create a visited map.
3. Mark the starting/source node as visited.
4. While the queue is not empty:
   a. Dequeue a node from the front of the queue.
   b. Process the dequeued/front node (print or store its value).  
   c. Enqueue all unvisited adjacent nodes and mark them as visited.


#### Time and Space Complexity  
- **Time Complexity:** O(V + E), where V = vertices, E = edges.  
- **Space Complexity:** O(V), for the visited array and queue.  

#### Applications of BFS:
- Shortest Path Finding
- Cycle Detection
- Connected Components
- Topological Sorting
- Level Order Traversal of Binary Trees
- Network Routing (e.g., finding shortest routes in networks).  

# Depth First Search Traversal (DFS Traversal): Directed Graph  

- Traversal technique where vertices are visited by exploring as far as possible along each branch before backtracking.  
- To avoid visiting a node more than once, a **visited map** is used.  

### DFS Algorithm  

1. Start from a given source node (`src`).  
2. Mark the current node (`src`) as visited.  
3. Process the current node (e.g., print or store its value).  
4. Recursively visit all unvisited neighbors of the current node.  
5. If there are any remaining unvisited nodes after completing the traversal from the source, repeat the process for them.


### Time and Space Complexity  

- **Time Complexity:** O(V + E), where V = vertices, E = edges.  
- **Space Complexity:** O(V), for the recursion stack and visited map.  


##### Applications of DFS  

- Detecting Cycles in a Graph  
- Pathfinding  
- Topological Sorting (in Directed Acyclic Graphs - DAGs)  
- Strongly Connected Components (SCC)  
- Solving Maze and Puzzle Problems  
