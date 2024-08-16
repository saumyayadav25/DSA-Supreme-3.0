// leetcode 1823. Find the Winner of the Circular Game

class Solution {
public:
    int findTheWinner(int n, int k) {
        // all players should go into a Queue
        queue<int>q;
        for(int i = 1; i <= n; i++) q.push(i);
        while(q.size() > 1){
            // stimulate the game
            for(int i = 1; i < k; i++){
                auto player = q.front();
                q.pop();
                q.push(player); //it is not eliminated yet
            }
            // kth player must be eliminated
            q.pop();
        }
        return q.front(); //winner
    }
};