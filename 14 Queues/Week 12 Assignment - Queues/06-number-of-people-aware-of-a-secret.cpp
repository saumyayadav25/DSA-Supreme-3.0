// leetcode 2327. Number of People Aware of a Secret

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int M = 1e9 + 7;
        int curr = 0; //active spreader
        int ans = 1; //person who know about secret
        queue<pair<int,int> > delayQ, forgetQ; //<that day, kitne new logo ko secret pata laga>
        delayQ.push({1,1});
        forgetQ.push({1,1});
        for(int i = 1; i <= n; i++){
            // step 1. Active spreader and person know about secret kam karo
            if(!forgetQ.empty() && forgetQ.front().first + forget <= i){
                auto front = forgetQ.front();
                forgetQ.pop();
                auto no = front.second;
                ans = (ans - no + M) % M;
                curr = (curr - no + M) % M;
            }
            // step 2. make new active spreader
            if(!delayQ.empty() && delayQ.front().first + delay <= i){
                auto front = delayQ.front();
                delayQ.pop();
                curr = (curr + front.second) % M; //activated
            }
            // step 3. spread the secret
            if(curr > 0){
                ans = (ans + curr) % M;
                delayQ.push({i,curr});
                forgetQ.push({i,curr});
            }
        }
        return ans;
    }
};