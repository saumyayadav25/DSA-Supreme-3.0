// leetcode 44. Wildcard matching

class Solution {
public:
    bool solveRec(string& s, string& p, int i, int j){
        // base cases
        if(i == s.length() && j == p.length()) return true; //sare characters match hogye hai
        if(j == p.length()){
            // pattern khtm hogya, but string khtm nhi hui
            return false;
        }
        if(i == s.length()){
            // agar sare bache hue characters * hai, then true else false
            for(int k = j; k<p.length();k++){
                if(p[k] != '*') return false;
            }
            // reached here -> sare characters * mile p string me
            return true;
        }
        // main logic: match or no match
        if(p[j] == '?' || s[i] == p[j]){ //single character match
            return solveRec(s,p,i+1,j+1);
        }
        else if(p[j] == '*'){
            // * can be empty string, or any character
            return solveRec(s,p,i+1,j) || solveRec(s,p,i,j+1);
        }
        else{
            // no match
            return false;
        }
    }

    bool solveMem(string& s, string& p, int i, int j, vector<vector<int> >&dp){
        // base cases
        if(i == s.length() && j == p.length()) return true; //sare characters match hogye hai
        if(j == p.length()){
            // pattern khtm hogya, but string khtm nhi hui
            return false;
        }
        if(i == s.length()){ //important part
            // agar sare bache hue characters * hai, then true else false
            for(int k = j; k<p.length();k++){
                if(p[k] != '*') return false;
            }
            // reached here -> sare characters * mile p string me
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool ans;
        // main logic: match or no match
        if(p[j] == '?' || s[i] == p[j]){ //single character match
            ans =  solveMem(s,p,i+1,j+1,dp);
        }
        else if(p[j] == '*'){
            // * can be empty string, or any character
            ans =  solveMem(s,p,i+1,j,dp) || solveMem(s,p,i,j+1,dp);
        }
        else{
            ans =  false;
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    bool solveTab(string& s, string& p, int m, int n){
        vector<vector<int> >dp(m+1, vector<int>(n+1,0));
        dp[m][n] = true;

        for(int col = 0; col < n; col++){
            bool flag = true;
            for(int k = col; k<p.length();k++){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[m][col] = flag;
        }

        for(int i = m-1; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                bool ans;
                if(p[j] == '?' || s[i] == p[j]){
                    ans =  dp[i+1][j+1];
                }
                else if(p[j] == '*'){
                    ans =  dp[i+1][j] || dp[i][j+1];
                }
                else{
                    ans =  false;
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    bool solveTabSO(string& s, string& p, int m, int n){
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        next[n] = true;

        for(int col = 0; col < n; col++){
            bool flag = true;
            for(int k = col; k<p.length();k++){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            next[col] = flag;
        }

        for(int i = m-1; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                bool ans;
                if(p[j] == '?' || s[i] == p[j]){
                    ans =  next[j+1];
                }
                else if(p[j] == '*'){
                    ans =  next[j] || curr[j+1];
                }
                else{
                    ans =  false;
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }


    bool isMatch(string s, string p) {
        // bool ans = solveRec(s,p,0,0);

        int m = s.length();
        int n = p.length();
        // vector<vector<int> >dp(m+1, vector<int>(n+1,-1));
        // bool ans = solveMem(s,p,0,0,dp);

        // bool ans = solveTab(s,p,m,n);

        bool ans = solveTabSO(s,p,m,n);
        return ans;
    }
};