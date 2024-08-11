// leetcode 2104. Sum of Subarray Ranges

class Solution {
public:
    vector<int>nextSmallerElement(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);
        for(int i = v.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() != -1 && v[st.top()] > v[i]) st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerElement(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);
        for(int i = 0; i < v.size() ; i++){
            while(!st.empty() && st.top() != -1 && v[st.top()] >= v[i]) st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        auto next = nextSmallerElement(arr);
        auto prev = prevSmallerElement(arr);
        long long sum = 0; //sum of all sub-array's minimum elements
        for(int i = 0; i< arr.size() ; i++){
            // for each index element, need to find how many times it is contributing to the "sum"
            int nexti = next[i] == -1 ? arr.size() : next[i];
            int previ = prev[i];
            int left = i - previ;
            int right = nexti - i;
            sum += left * right * arr[i];
        }
        return sum;
    }


    vector<int>nextgreaterElement(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);
        for(int i = v.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() != -1 && v[st.top()] < v[i]) st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevgreaterElement(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);
        for(int i = 0; i < v.size() ; i++){
            while(!st.empty() && st.top() != -1 && v[st.top()] <= v[i]) st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        auto next = nextgreaterElement(arr);
        auto prev = prevgreaterElement(arr);
        long long sum = 0; //sum of all sub-array's minimum elements
        for(int i = 0; i< arr.size() ; i++){
            // for each index element, need to find how many times it is contributing to the "sum"
            long nexti = next[i] == -1 ? arr.size() : next[i];
            long previ = prev[i];
            long left = i - previ;
            long right = nexti - i;
            sum += left * right * arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        auto sumofMaximums = sumSubarrayMaxs(nums);
        auto sumofMinimums = sumSubarrayMins(nums);
        return sumofMaximums-sumofMinimums;
    }
};