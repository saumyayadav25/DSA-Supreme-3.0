// already done in strings class-2

// leetcode 1047: remove all adjacent duplicates in String

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto ch:s){
            if(!st.empty() && st.top() == ch){
                // pair up
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        string ans;
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};