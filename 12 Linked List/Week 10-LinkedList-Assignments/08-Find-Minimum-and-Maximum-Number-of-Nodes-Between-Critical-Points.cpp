// leetcode 2058: Find the Minimum and Maximum Number of Nodes Between Critical Points

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1,-1};  //store minDist, maxDist
        ListNode* prev = head;
        if(!prev) return ans;
        ListNode* curr = head->next;
        if(!curr) return ans;
        ListNode* nxt = head->next->next;
        if(!nxt) return ans;

        int firstCP = -1;
        int lastCP = -1;
        int minDist = INT_MAX;
        int i = 1;
        while(nxt){
            bool isCP = ((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val) ) ? true : false;
            if(isCP && firstCP==-1){
                firstCP = i;
                lastCP = i;
            }
            else if(isCP){
                minDist = min(minDist,i-lastCP);
                lastCP = i;
            }
            i++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }
        if(lastCP == firstCP){
            // only one critical points was found
            return ans;
        }
        else{
            ans[0]=minDist;
            ans[1]=lastCP-firstCP;
        }
        return ans;
    }
};