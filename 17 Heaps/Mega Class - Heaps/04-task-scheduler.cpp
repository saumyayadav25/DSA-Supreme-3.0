// leetcode 621. Task Scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(auto task:tasks) freq[task]++;
        
        priority_queue<pair<int,char>, vector<pair<int,char>>> maxHeap;
        
        for(auto e: freq){
            maxHeap.push({e.second, e.first});
        }

        int time = 0;
        while(!maxHeap.empty()){
            int cycle = n + 1;
            vector<pair<int,char>> temp;

            while(cycle > 0 && !maxHeap.empty()){
                auto [freq, task] = maxHeap.top();
                maxHeap.pop();
                freq--;
                time++;
                cycle--;
                // push remaining tasks
                temp.push_back({freq,task});
            }
            for(auto leftTask: temp){
                if(leftTask.first > 0){
                    maxHeap.push(leftTask);
                }
            }
            // adding idle time
            if(!maxHeap.empty()){
                time += cycle;
            }
        }
        return time;
    }
};