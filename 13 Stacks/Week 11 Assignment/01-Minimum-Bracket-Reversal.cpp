// GFG: Count the Reversals

int countRev (string s){
    // if odd sized string->not possible to make pairs
    if(s.size() & 1) return -1;
    int ans = 0;
    stack<char>st;
    for(char ch:s){
        if(ch=='{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top()=='{') st.pop();
            else st.push(ch);
        }
    }
    // stack is still not empty, count reversals
    while (!st.empty()) {
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();
        if (a == b) {
            ans += 1;
        } else {
            ans += 2;
        }
    }

    return ans;
}