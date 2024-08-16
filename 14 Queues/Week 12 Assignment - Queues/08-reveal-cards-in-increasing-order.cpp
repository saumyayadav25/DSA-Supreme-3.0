// leetcode 950. Reveal Cards in Increasing Order

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int>q;
        vector<int>ans(deck.size());

        // put indices of ans into q
        for(int i = 0; i < ans.size() ; i++) q.push(i);

        // reverse simulation + filling using sorted deck
        for(int i = 0; i < deck.size() ; i++){
            // 1. Reveal
            ans[q.front()] = deck[i];
            q.pop();
            // 2. push front to bottom
            if(!q.empty()){
                // q.push(q.front());
                // q.pop();
                auto f = q.front();
                q.pop();
                q.push(f);
            }
        }
        return ans;
    }
};