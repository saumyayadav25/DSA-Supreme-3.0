// leetcode 44. Wildcard Matching

class Solution {
public:
    bool isMatchHelper(string&s, int si, string&p, int pi){
        // base case
        if(si == s.size() && pi == p.size()) return true;
        if(si == s.size() && pi < p.size()){
            // return true iff only * is present
            while(pi<p.size()){
                if(p[pi]!='*') return false;
                pi++;
            }
            return true;
        }
        // single char matching
        if(s[si] == p[pi] || '?' == p[pi]){
            return isMatchHelper(s,si+1,p,pi+1);
        }
        if(p[pi]=='*'){
            // treat * as empty or null
            bool caseA = isMatchHelper(s, si, p, pi+1);
            // let * consume 1 character
            bool caseB = isMatchHelper(s,si+1,p,pi);
            return caseA || caseB;
        }
        // char doesnt match
        return false;
    }
    bool isMatch(string s, string p) {
        int si = 0;  //pointer index for s string
        int pi = 0;  //pointer index for p string

        return isMatchHelper(s,si,p,pi);
    }
};