// leetcode 994. Rotting Oranges

class Solution{
public:
    int orangesRotting(vector<vector<int>> &grid){
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;

        // Step 1: put all the rotten oranges to the queue
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == 2) q.push({i, j}); //push rotten oranges
                else if (grid[i][j] == 1) freshOranges++;
            }
        }

        if (!freshOranges) return 0; // no fresh oranges present at T=0

        int minutes = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Step 2: Perform BFS
        while (!q.empty()){
            int size = q.size();
            bool hasRottenNew = false;

            // processing current level / current T / current minute
            for (int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();

                for (auto dir : directions){
                    int newRow = curr.first + dir.first;
                    int newCol = curr.second + dir.second;

                    // if adj cell is a fresh Orange, rot it.
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        freshOranges--;
                        q.push({newRow, newCol}); // for next level
                        hasRottenNew = true;
                    }
                }
            }
            // after current level is over
            if (hasRottenNew) minutes++;
        }

        // Step 3: checking
        if (freshOranges > 0) return -1;
        return minutes;
    }
};