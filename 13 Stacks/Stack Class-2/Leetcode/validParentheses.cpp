// leetcode 20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.length();i++){
            char ch = s[i];
            // ch -> open or close bracket
            // open -> sirf push
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
            }
            // close -> check if same type ka open hai ya nhi
            else{
                // check at top of stack ki same type ka open bracket hai ya nhi
                // bracket match cases
                if(ch==')' && !st.empty() && st.top()=='('){
                    st.pop();
                }
                else if(ch==']' && !st.empty() && st.top()=='['){
                    st.pop();
                }
                else if(ch=='}' && !st.empty() && st.top()=='{'){
                    st.pop();
                }
                // bracket not matching
                else{
                    return false;
                }
            }
        }
        // check stack size
        if(st.size()==0) return true;
        else return false;
    }
};