// HW
//gfg: Expression contains redundant bracket or not

class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> st;
        for(int i=0; i<s.size();i++){
            char ch = s[i];
            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/') st.push(ch);
            else{
                // closing bracket
                if(ch==')'){
                    bool isredundant = true;
                    while(!st.empty() && st.top() != '('){
                        char top = st.top();
                        if(top=='+' || top=='-' || top=='*' || top=='/') isredundant = false;
                        st.pop();
                    }
                    if (!st.empty()) {
                        st.pop();
                    }
                    if(isredundant) return true;
                }
            }
        }
        return false;
    }
};
