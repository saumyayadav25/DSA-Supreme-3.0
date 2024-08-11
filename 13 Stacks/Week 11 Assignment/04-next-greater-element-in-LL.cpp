// leetcode 1019. Next Greater Node in Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;
        while(head){
            ll.push_back(head->val);
            head = head->next;
        }
        stack<int>st;
        // vector<int> ans(ll.size());   // initialized with 0
        for(int i = 0; i<ll.size();i++){
            while(!st.empty() && ll[i]>ll[st.top()]){
                // means ith element is the next greater of the element index
                int kids = st.top();
                st.pop();
                ll[kids] = ll[i]; 
            }
            st.push(i);
        }
        while(!st.empty()){
            ll[st.top()]= 0; st.pop();
        }
        ll[ll.size()-1] = 0;
        return ll;
    }
};


// alternative approach
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // creating a stack of pairs to hold index-value pairs
        stack<pair<int,int>>st;
        // creating a vector to store the final result
        vector<int>ans;
        int i = 0;
        // iterate through LL until head becomes NULL
        while(head){
            ans.push_back(0);

            while(!st.empty() && st.top().second<head->val){
                auto top = st.top();
                st.pop();
                ans[top.first]=head->val;
            }
            st.push({i++, head->val});
            head=head->next;
        }
        return ans;
    }
};