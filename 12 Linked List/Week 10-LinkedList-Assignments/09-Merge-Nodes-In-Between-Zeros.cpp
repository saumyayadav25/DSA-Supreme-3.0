// leetcode 2181 : Merge Nodes in Between Zeros

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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return 0;
        ListNode*slow = head, *fast = head->next, *newLastNode=0;
        int sum = 0;
        while(fast){
            if(fast->val != 0) sum += fast->val;
            else{
                //fast->val==0
                    slow->val = sum;
                    newLastNode = slow;
                    slow = slow->next;
                    sum = 0;
            }
            fast = fast->next;
        }
        ListNode*temp = newLastNode->next;
        // just formed new list
        newLastNode->next = 0;
        // Deleting old list
        while(temp){
            ListNode*nxt = temp->next;
            delete temp;
            temp = nxt;
        }
        return head;
    }
};