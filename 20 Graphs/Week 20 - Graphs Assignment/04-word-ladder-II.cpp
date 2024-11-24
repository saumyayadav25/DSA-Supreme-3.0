// gfg : Word Ladder II

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        queue< pair<vector<string>, int> > q; //first: sequence, second: level
        q.push({{beginWord}, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        int prevLevel = -1;
        vector<string>toBeRemoved;

        //main traversal logic 
        while(!q.empty()) {
            auto frontPair = q.front();
            q.pop();

            auto currSeq = frontPair.first;
            string frontString = currSeq[currSeq.size() - 1];
            int frontDistance = frontPair.second;

            if(frontDistance != prevLevel){
                for(auto s: toBeRemoved){
                    st.erase(s);
                }
                toBeRemoved.clear();
                prevLevel = frontDistance;
            }
            //check if front ki node is the endWord or not 
            if(frontString == endWord) {
                ans.push_back(currSeq);
            }

            else {
                for(int index = 0; index < frontString.length(); index++) {
                    char originalCharacter = frontString[index]; //why ?
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        frontString[index] = ch;
                        //check if the new string is there in the dictionary or not 
                        if(st.find(frontString) != st.end()) {
                            //valid string
                            auto temp = currSeq;
                            temp.push_back(frontString);
                            q.push({temp, frontDistance + 1});
                            toBeRemoved.push_back(frontString);
                        }
                    }
                    //backtrack -> don't forget this
                    frontString[index] = originalCharacter;
                }
            }
        }
        return ans;
    }
};


// leetcode 126: MLE