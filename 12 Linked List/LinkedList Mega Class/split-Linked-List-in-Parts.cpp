// leetcode 725: Split Linked List in Parts

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = 0;
        // ListNode ki jgh auto
        auto it = head;
        while(it){
            N++;
            it = it->next;
        }
        //determine size of each part/bucket
        int partSize = N/k;
        int extraNodes = N%k;  //divide bucket by bucket
        vector<ListNode*> ans(k,nullptr);
        it = head;
        for(int i=0;i<k && it;i++){
            ans[i] = it;
            int currentPartSize = partSize + (extraNodes>0 ? 1:0);
            extraNodes--;

            for(int j=0;j<currentPartSize-1;j++) it = it->next;
            
            auto nextPartStarting = it->next;
            it->next = nullptr;
            it = nextPartStarting;
        }
        return ans;
    }
};