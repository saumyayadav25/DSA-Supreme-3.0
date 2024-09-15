// leetcode 1753. Maximum Score From Removing Stones

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // maxHeap
        priority_queue<int, vector<int>> maxHeap;
        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);

        int score = 0;

        while(maxHeap.size() > 1){
            int pile1 = maxHeap.top(); maxHeap.pop();
            int pile2 = maxHeap.top(); maxHeap.pop();

            pile1--, pile2--;
            score++;

            if(pile1 > 0) maxHeap.push(pile1);
            if(pile2 > 0) maxHeap.push(pile2);
        }
        return score;
    }
};