// leetcode647. Palindromic Substrings
class Solution {
public:
    int expandAroundCenter(string s, int i, int j){
        int count = 0;
        while(i>=0 && j<=s.length() && s[i]==s[j]){ //i and j should be valid index
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalCount = 0;
        for(int center = 0; center < s.length(); center++){
            //odd length substr
            int i = center;
            int j = center;
            int oddPalindromeSubstrCount = expandAroundCenter(s, i ,j);
            //even length substr
            i = center;
            j = center + 1;
            int evenPalindromeSubstrCount = expandAroundCenter(s, i ,j);
            totalCount = totalCount + oddPalindromeSubstrCount + evenPalindromeSubstrCount;
        }
        return totalCount;
    }
};
