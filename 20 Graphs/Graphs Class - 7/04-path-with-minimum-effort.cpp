// leetcode 1631. Path With Minimum Effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int> >>, greater<pair<int,pair<int,int> >>  > pq; //min heap
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int> > dist(row, vector<int>(col, INT_MAX));
        //initial state maintain
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        //dijkstra's logic 
        while(!pq.empty()) {
            pair<int,pair<int,int> > frontNode = pq.top();
            pq.pop();
            int currAbsDifference = frontNode.first;
            int x = frontNode.second.first;
            int y = frontNode.second.second;
            //check for destination
            if(x == row-1 && y == col-1) {
                return dist[x][y];
            }
            else {
                //then do up, down, left, right movement 
                int dx[] = {0,-1,0,1};
                int dy[] = {-1,0,1,0};
                for(int i=0; i<4; i++) {
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    // check if new coordinates are safe for movement
                    if(newX >=0 && newY >= 0 && newX < row && newY < col) {
                        int newAbsDifference = abs(heights[x][y] - heights[newX][newY]);
                        // we want to store maximum abs difference
                        int newMaxDifference = max(currAbsDifference, newAbsDifference);
                        // we want to store minimum effort/distance
                        if(newMaxDifference < dist[newX][newY]) {
                            dist[newX][newY] = newMaxDifference;
                            // jab bhi koi new MaxDifference calculate krenge tab pq me bhi push krna hai 
                            pq.push({newMaxDifference,{newX,newY}});
                        }
                    }
                }
            }
        }
        return 0;
    }
};