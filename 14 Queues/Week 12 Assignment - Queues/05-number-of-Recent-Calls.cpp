// leetcode 933. Number of Recent Calls

class RecentCounter {
    queue<int>q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        // step 1.
        q.push(t);
        // step 2. pop invalid request older than t-3000
        while(!q.empty() && q.front() < (t-3000)) q.pop();
        // step 3. now q has only number of recent calls
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */