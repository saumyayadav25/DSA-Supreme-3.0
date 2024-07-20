// leetcode 1910: Remove All Occurrences of a Substring
// Already done in optimised way in char arrays and strings class-2, doing with recursion now

class Solution {
public:
    void removeOCCRE(string &s, string &part){
        int found = s.find(part);
        if(found!= string::npos){
            //part string has been located
            //remove it
            string left_part = s.substr(0,found);
            string right_part = s.substr(found+part.size(),s.size());
            s = left_part+right_part;

            removeOCCRE(s,part);
        }
        else{
            //base case
            // all the occurrences of part has been removed from s
            return;
        }
    }
    string removeOccurrences(string s, string part) {
        removeOCCRE(s,part);
        return s;
    }
};
