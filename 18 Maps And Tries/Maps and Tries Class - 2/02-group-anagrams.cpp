// leetcode 49. Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > map;

        for(int i = 0; i < strs.size(); i++){
            string original = strs[i];
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            map[copy].push_back(original);
        }
        vector<vector<string> > ans;
        for(auto i: map){ // i: key and value ka pair
            ans.push_back(i.second);
        }
        return ans;
    }
};