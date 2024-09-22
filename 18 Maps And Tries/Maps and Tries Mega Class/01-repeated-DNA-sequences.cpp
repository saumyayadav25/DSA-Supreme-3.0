// leetcode 187. Repeated DNA Sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> seqCount; // stores 10 sized window substring
        vector<string>ans;
        if(s.size() < 10) return {};

        // slide the 10 size window
        for(int i = 0; i <= s.size()-10; i++){
            string current10SizeWindowSubstring = s.substr(i,10);
            seqCount[current10SizeWindowSubstring]++;
        }

        // for(auto it:seqCount){
        //     if(it.second > 1){
        //         ans.push_back(it.first);
        //     }
        // }
        
        // destructuring code
        // seqCount: {string,int} extract krte time copy banke ayegi
        for(auto &[subStr, freq]:seqCount){
            if(freq>1) ans.push_back(subStr);
        }
        return ans;
    }
};