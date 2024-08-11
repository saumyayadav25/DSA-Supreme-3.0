// GFG: The Celebrity Problem

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        stack<int>st;

        // step 1-> push all persons into stack
        for(int i = 0; i < n;i++){
            st.push(i);
        }
        // step 2-> run discard method to get a mightBeCelebrity
        while(st.size()!=1){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            // if a knows b
            if(mat[a][b]){
                // a is not celebrity, b might be
                st.push(b);
            }
            else{
                // b is not celebrity, a might be
                st.push(a);
            }
        }
        // Step 3-> check that if that single person is actually celebrity
        int mightBeCelebrity = st.top(); st.pop();
        // celebrity should not know anyone
        for(int i = 0; i < n;i++){
            if(mat[mightBeCelebrity][i]!=0) return -1;
        }
        // everyone should know celebrity
        for(int i = 0; i < n; i++){
            if(mat[i][mightBeCelebrity]==0 && i!=mightBeCelebrity) return -1;
        }
        // mightBeCelebrity is the celebrity
        return mightBeCelebrity;
    }
};