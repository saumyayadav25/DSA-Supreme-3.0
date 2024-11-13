// gfg: Sum Equals to Sum

// TC: O(N^2)
// if map me har bar worst case me insert hoga toh O(N^3): TC but assume ki O(1) me work kr rha hai map abhi in average case
// SC: O(N)
class Solution {
  public:
    bool findPairs(vector<int>& arr) {
        unordered_map<int,bool>map;
        int n = arr.size();
        // pairs
        for(int i = 0; i < n; i++){
          for(int j = i + 1; j < n; j++){
            int sum = arr[i] + arr[j];
            if(map.find(sum) != map.end()){
              return true;
            }
            else{
              map[sum] = true;
            }
          }
        }
        return false;
    }
};