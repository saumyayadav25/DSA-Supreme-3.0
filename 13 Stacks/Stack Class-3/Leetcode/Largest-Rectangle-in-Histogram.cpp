// leetcode 84: Largest Rectangle in Histogram

class Solution {
public:
    void nextSmallerElement(vector<int>&heights, vector<int>&nextAns){
        stack<int>st;
        st.push(-1);
        int n = heights.size();
        for(int i = n-1; i>=0; i--){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }
            // agar yaha tk pahucha hu toh koi chota number stack top pe hai ya fir -1 stack top pe h
            nextAns.push_back(st.top());
            // current number ko toh stack me push krna hi h 
            st.push(i);
        }
    }
    void prevSmallerElement(vector<int>&heights, vector<int>&prevAns){
        stack<int>st;
        st.push(-1);
        int n = heights.size();
        for(int i = 0; i<n; i++){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }
            // agar yaha tk pahucha hu toh koi chota number stack top pe hai ya fir -1 stack top pe h
            prevAns.push_back(st.top());
            // current number ko toh stack me push krna hi h 
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextAns;
        vector<int> prevAns;
        nextSmallerElement(heights, nextAns);
        reverse(nextAns.begin(),nextAns.end());
        // ye hi bhool jata hu
        for(int i=0; i<nextAns.size();i++){
            if(nextAns[i]==-1){
                nextAns[i]=nextAns.size();
            }
        }
        // corner case-> = wala bhul jata 
        prevSmallerElement(heights, prevAns);

        int maxArea = INT_MIN;
        for(int i = 0; i<nextAns.size();i++){
            int width = nextAns[i]-prevAns[i]-1;
            int height = heights[i];
            int currArea = width * height;
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};