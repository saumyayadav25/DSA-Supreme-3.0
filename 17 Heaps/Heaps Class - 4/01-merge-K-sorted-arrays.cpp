// gfg: Merge K Sorted Arrays

// class: to help access next element(index) after popping from pq
class Info{
    public:
        int data;
        int rIndex;
        int cIndex;
        Info(int x, int y, int z){
            // data = x; // use this: good practice
            this->data = x;
            this->rIndex = y;
            this->cIndex = z;
        }
};

class compare{
public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data; //min heap
    }
};

class Solution{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K){
        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int>ans;
        int totalRows = arr.size();
        int totalColumns = arr[0].size();
        // process first k elements
        // har array ka first element hi k element banayega
        for(int row = 0; row < arr.size(); row++){
            int element = arr[row][0];
            Info* temp = new Info(element,row,0);
            pq.push(temp);
        }

        // main logic
        while(!pq.empty()){
            Info* front = pq.top();
            pq.pop();
            // include in aswer
            int frontdata = front->data;
            int front_rindex = front->rIndex;
            int front_cindex = front->cIndex;
            ans.push_back(front->data);
            // check if aage data hai front element ke, then push it inside the pq
            if(front_cindex+1 < totalColumns){
                int element = arr[front_rindex][front_cindex+1];
                Info* temp = new Info(element, front_rindex, front_cindex+1);
                pq.push(temp);
            }
        }
        return ans;
    }
};