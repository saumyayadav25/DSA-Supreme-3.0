// leetcode 30. Substring with Concatenation of All Words

class Solution {
public:
    // track individual word count
    unordered_map<string,int> map;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        for(int i = 0; i < words.size(); i++){
            map[words[i]]++;
        }
        int wordLength = words[0].length();
        // offset logic: start->0,1,2,.. < wordLength
        for(int offset = 0; offset < wordLength; offset++){
            unordered_map<string, int> visited;
            // check if answer found, track count for that
            int count = 0;
            // wordLength ke substring check kro
            for(int i = offset; i + wordLength <= s.length(); i = i + wordLength){
                string substr = s.substr(i, wordLength);
                // check wheather the substr is valid or not
                if(map.find(substr) == map.end()){
                    // invalid string
                    // purane sare answer ko bhulna chahiye and nayi start krni chahiye
                    visited.clear();
                    count = 0;
                }
                else{
                    // valid string
                    // mark it visited
                    visited[substr]++;
                    count++;

                    // GAME CHANGER LOGIC-removal
                    while(visited[substr] > map[substr]){
                        // har word removal par visited and count dono me se wo word hatega
                        string temp = s.substr(i-(count-1)*wordLength, wordLength);
                        visited[temp]--;
                        count--;
                    }
                    // answer mila kya??
                    if(count == words.size()){
                        // found answer
                        // insert starting index in answer
                        ans.push_back(i-(count-1)*wordLength);
                    }
                }
            }
        }
        return ans;
    }
};