// gfg: Sum of Minimum and Maximum Elements of All Subarray of size k-> not available for practice on gfg

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

// max sliding window->lc 239
    int sumOfMinMaxOfAllWindows(vector<int> nums, int k) {
        deque<int>dq,dq2;
        int ans = 0;
        // process first window
        for(int i = 0; i < k; i++){
            int element = nums[i];
            // int dqIndex = dq.front();
            while(!dq.empty() && nums[dq.back()] >= element){
                dq.pop_back();
            }
            // remove big element
            while(!dq2.empty() && nums[dq2.back()] <= element){
                dq2.pop_back();
            }
            // insert current element
            dq.push_back(i);
            dq2.push_back(i);
        }
        // get answer for first window
        ans += nums[dq.front()] + nums[dq2.front()];

        // process remaining windows
        for(int i = k; i < nums.size(); i++){
            // removal
            if(!dq.empty() && dq.front() < i-k+1) dq.pop_front();
            if(!dq2.empty() && dq2.front() < i-k+1) dq2.pop_front();
            // addition
            int element = nums[i];
            while(!dq.empty() && nums[dq.back()] >= element){
                dq.pop_back();
            }
            while(!dq2.empty() && nums[dq2.back()] <= element){
                dq2.pop_back();
            }
            dq.push_back(i);
            dq2.push_back(i);
            // ans store
            ans += nums[dq.front()] + nums[dq2.front()];
        }
        return ans;
    }


int main(){
    vector<int> v {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sumOfMinMaxOfAllWindows(v,k) << endl;
    return 0;
}