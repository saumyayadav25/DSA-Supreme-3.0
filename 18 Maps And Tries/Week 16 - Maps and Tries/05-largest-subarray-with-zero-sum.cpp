// gfg: Largest Subarray with 0 sum

// TC: O(N) assuming map working in O(1)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>map;
        int csum = 0;
        int ans = 0; //store max length of subarray with 0 sum
        for(int i = 0; i < n; i++){
            csum += arr[i];
            if(csum == 0){
                ans = max(ans, i + 1);
            }
            else if(map.find(csum) == map.end()){
                map[csum] = i;
            }
            else{
                // map has csum already
                ans = max(ans, i - map[csum]);
            }
        }
        return ans;
    }
};