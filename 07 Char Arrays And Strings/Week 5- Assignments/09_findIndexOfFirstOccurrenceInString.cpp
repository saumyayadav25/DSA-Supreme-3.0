// leetcode 28: Find the Index of the First Occurrence in a String
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        for(int i=0;i<=n-m;i++){
            for(int j=0;j<m;j++){
                if(needle[j]!=haystack[i+j]) break;
                if(j==m-1) return i;
            }
        }
        return -1;
    }
};