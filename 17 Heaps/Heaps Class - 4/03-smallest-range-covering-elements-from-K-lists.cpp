// leetcode 632. Smallest Range Covering Elements from K Lists

class Info{
    public:
        int data;
        int rIndex;
        int cIndex;
        Info(int a, int b, int c){
            data = a;
            rIndex = b;
            cIndex = c;
        }
};

class compare{
    public:
        bool operator()(Info* a, Info* b){
            return a->data > b->data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare>pq;
        
        vector<int>ans;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        // process first k elements
        int totalRows = nums.size();
        // int totalColumns = nums[0].size(); //can have different number of columns

        for(int row = 0; row < totalRows; row++){
            int element = nums[row][0];
            Info* temp = new Info(element, row, 0);
            pq.push(temp);
            maxi = max(maxi,element);
            mini = min(mini,element);
        }

        // store the smallest difference wali values
        int ans_start = mini;
        int ans_end = maxi;
        
        // main logic
        while(!pq.empty()){
            // front nikalo
            Info* front = pq.top();
            pq.pop();

            int frontData = front->data;
            int front_rindex = front->rIndex;
            int front_cindex = front->cIndex;

            mini = frontData; // ye bhul jata hu

            // ans update
            if((maxi - mini) < (ans_end - ans_start)){
                // found a new and small difference
                ans_start = mini;
                ans_end = maxi;
            }

            // aage element hai toh insert karo
            int currTotalColumns = nums[front_rindex].size();
            if(front_cindex + 1 < currTotalColumns){
                int element = nums[front_rindex][front_cindex + 1];
                Info* temp = new Info(element, front_rindex, front_cindex + 1);
                maxi = max(maxi, element);
                pq.push(temp);
            }
            else{
                break;
            }
        }
        ans.push_back(ans_start);
        ans.push_back(ans_end);
        return ans;
    }
};