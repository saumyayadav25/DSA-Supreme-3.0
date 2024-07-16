// leetcode 890. Find and Replace Pattern
class Solution {
public:
    void normalise(string &str){
        char start = 'a';
        unordered_map<char,char> mapping;
        for(int i=0; i<str.length();i++){
            char stringCharacter = str[i];
            if(mapping.find(stringCharacter) == mapping.end()){
                //mapping not present already
                mapping[stringCharacter] = start; //create it
                start++;
            }
        }
        //mapping created
        //string str ko update normalise krdo using mapping
        for(int i=0; i<str.length();i++){
            char mappedCharacter = mapping[str[i]];
            str[i] = mappedCharacter;
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        //normalise the pattern
        normalise(pattern);

        //traverse on words->normalise them -> check if they are equal ko pattern or not
        for(int i=0; i<words.size();i++){
            string currWord = words[i];
            normalise(currWord);
            if(currWord.compare(pattern) == 0){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};