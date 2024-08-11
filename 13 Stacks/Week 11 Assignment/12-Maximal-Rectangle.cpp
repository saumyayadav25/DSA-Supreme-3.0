// leetcode 85. Maximal Rectangle

// pre-requisite: Largest Rectangle in histogram

class Solution {
    void nextSmallerElement(vector<int>&heights, vector<int>&nextAns){
        stack<int>st;
        st.push(-1);
        int n = heights.size();
        for(int i = n-1; i>=0; i--){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }
            nextAns.push_back(st.top());
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
            prevAns.push_back(st.top());
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextAns;
        vector<int> prevAns;
        nextSmallerElement(heights, nextAns);
        reverse(nextAns.begin(),nextAns.end());
        for(int i=0; i<nextAns.size();i++){
            if(nextAns[i]==-1){
                nextAns[i]=nextAns.size();
            }
        }
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

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            vector<int> t;
            for(int j = 0; j < m; j++){
                t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);
        }
        int area = largestRectangleArea(v[0]);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                // update current row with previous values
                if(v[i][j]){
                    v[i][j] += v[i - 1][j];
                }
                else{
                    v[i][j] = 0;
                }
            }
            area = max(area,largestRectangleArea(v[i]));
        }
        return area;
    }
};

