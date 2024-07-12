// leetcode 767: Reorganize String
//O(nlogn): using priority queue, later on.
class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};
        for(int i=0; i<s.size();i++){
            hash[s[i]-'a']++;
        } //O(n)

        //find most frequent char
        char most_freq_char;
        int max_freq = INT_MIN;
        for(int i=0;i<26;i++){
            if(hash[i]>max_freq){
                max_freq = hash[i];
                most_freq_char = i +'a';
            }
        }
        int index = 0;
        while(max_freq>0 && index<s.size()){
            s[index] = most_freq_char;
            max_freq--;
            index += 2;
        } //O(n)
        if(max_freq != 0){
            return "";
        }
        hash[most_freq_char - 'a'] = 0;

        //place rest of the characters
        for(int i=0; i<26;i++){
            while(hash[i]>0){
                index = index>=s.size() ? 1:index;
                s[index]=i+'a';
                hash[i]--;
                index +=2;
            }
        } //O(26*n)
        return s;
    }
};