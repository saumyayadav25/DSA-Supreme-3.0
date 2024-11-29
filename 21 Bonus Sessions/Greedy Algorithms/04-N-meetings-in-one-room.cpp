// gfg: N meetings in one room

// TC: O(NlogN)
class Solution {
  public:
  static bool cmp(pair<int,int>a, pair<int,int>b){
    return a.second < b.second;
  }
    // Function to find the maximum number of meetings that can be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>> time;
        for(int i = 0; i < start.size(); i++){
            time.push_back({start[i], end[i]});
        }
        sort(time.begin(), time.end(), cmp); // sort based on ending time
        // include first meeting 
        int count = 1;
        int prevStart = time[0].first;
        int prevEnd = time[0].second;

        for(int i = 1; i < start.size(); i++){
            int currStart = time[i].first;
            int currEnd = time[i].second;
            if(currStart > prevEnd){
                // include kar skte hai
                count++;
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }
        
        return count;
    }
};