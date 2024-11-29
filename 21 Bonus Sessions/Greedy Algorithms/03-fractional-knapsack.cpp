// gfg: Fractional Knapsack

// TC:O(NlogN)
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<double>valWtRatio;
        for(int i = 0; i < val.size(); i++){
          double ratio = (val[i] * 1.0 / wt[i]);
          valWtRatio.push_back(ratio);
        }
        // to find the max ratio item, create a max heap
        priority_queue<pair <double, pair<int,int> >> pq;
        for(int i = 0; i < val.size(); i++){
          pq.push({valWtRatio[i],{val[i], wt[i]}});
        }
        // find the total value
        double totalValue = 0;
        while(capacity != 0 && !pq.empty()){ // don't forget to check for pq empty
          auto front = pq.top();
          pq.pop();

          double ratio = front.first;
          int value = front.second.first;
          int weight = front.second.second;

          // choose whether to include whole item or include fraction of item
          if(capacity >= weight){
            // whole item include
            totalValue += value;
            capacity -= weight;
          }
          else{
            // fraction of item include
            double valToInclude = ratio * capacity;
            totalValue += valToInclude;
            capacity = 0;
            break;
          }
        }
        return totalValue;
    }
};