// leetcode 76. Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if(len1 < len2){
            // no answer
            return "";
        }
        // on the basis of these 2 variables -> find out exact string, by using substr
        int ansIndex = -1;
        int ansLen = INT_MAX;

        unordered_map<char,int>sMap;
        unordered_map<char,int>tMap;

        // values fill krte hai tMap ke andar
        for(auto i: t){
            tMap[i]++;
        }
        int start = 0;
        int end = 0;
        // count tracks total matched characters in the window
        int count = 0;
        // variable size window logic
        while(end < s.length()){
            char ch = s[end]; 
            // update in sMap, kyuki sMap "s" wali string ki window me kon-konse characters hai unko track krne ke liye banaya hai
            sMap[ch]++;
            // possibility hai ye character "t" ke andar ho ya fir na ho
            // agar ye character "t" wali string ke andar hai->count kro
            if(sMap[ch] <= tMap[ch]){
                count++;
            }
            // count, that is, total numbers of matched characters exactly len2 ke equal ajaye
            if(count == len2){
                // minimise
                while(sMap[s[start]] > tMap[s[start]]){
                    sMap[s[start]]--;
                    start++;
                }
                // store ans
                int windowLength = end - start + 1;
                if(windowLength < ansLen){
                    ansLen = windowLength;
                    ansIndex = start;
                }
            }
            // ek valid ans nhi mila -> expand
            end++;
        }
        if(ansIndex == -1){
            return "";
        }
        else{
            return s.substr(ansIndex,ansLen);
        }
    }
};