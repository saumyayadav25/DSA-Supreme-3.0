//leetcode 1910: remove all occurrences of a substring
class Solution {
public:
    string removeOccurrences(string full, string part) {
        while(full.find(part) != string::npos){
            full.erase(full.find(part), part.length());
        }
        return full;
    }
};
