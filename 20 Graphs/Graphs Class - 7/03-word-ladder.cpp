// leetcode 127. Word Ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue< pair<string, int> > q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        // because i have used beginWord in queue, so i should erase it from dictionary or set
        st.erase(beginWord);
        //main traversal logic 
        while(!q.empty()) {
            pair<string,int> frontPair = q.front();
            q.pop();
            string frontString = frontPair.first;
            int frontDistance = frontPair.second;
            //check if front ki node is the endWord or not 
            if(frontString == endWord) {
                return frontDistance;
            }
            else {
                //toh ab change krne chalte h 
                for(int index = 0; index < frontString.length(); index++) {
                    char originalCharacter = frontString[index]; //why ?
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        frontString[index] = ch;
                        //check if the new string is there in the dictionary or not 
                        if(st.find(frontString) != st.end()) {
                            //valid string
                            q.push({frontString, frontDistance+1});
                            st.erase(frontString);
                        }
                    }
                    //backtrack -> don't forget this
                    frontString[index] = originalCharacter;
                }
            }
        }
        return 0;
    }
};




// A transformation sequence from word beginWord to word endWord -> editDistance jaisa hai ques
// dictionary -> trie 
// number of words in the *shortest transformation sequence* -> Dijkstra algo