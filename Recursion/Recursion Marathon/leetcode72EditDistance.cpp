// leetcode 72: Edit Distance
// Retry after DP to avoid TLE
class Solution {
public:
    int solve(string a, string b, int i, int j){
        //base case
        if(i>=a.length())             //word1 wali string end hogyi, word1 length may be less than word2
            return b.length()-j;
        if (j>=b.length())             //word2 end hogya
            return a.length()-i;

        int ans = 0;
        if(a[i]==b[j]){
            //match
            ans = 0 + solve(a,b,i+1, j+1);
        }
        else{
            //not match->perform operation
            //insert
            //plus 1 krna bhul jaoge
            int option1 = 1 + solve(a,b,i,j+1);
            //remove
            int option2 = 1 + solve(a,b,i+1,j);
            //replace
            int option3 = 1 + solve(a,b,i+1,j+1);

            ans = min(option1, min(option2, option3));
        }
        return ans;
    }
    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int ans = solve(word1, word2,i,j);
        return ans;
    }
};