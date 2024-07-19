// leetcode 25: Reverse Nodes in k-Group

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
    int getLength(ListNode* &head){
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // LL is empty
        if(head == NULL){
            return head;
        }
        // single node
        if(head->next == NULL){
            return head;
        }
        // atleast 2 node
        int position = 0;
        // check for LL length
        int len = getLength(head);
        if(len<k){
            // no need to reverse as per question
            return head;
        }

        // 1case hum, baki recursion sambhal lega
        // reverse k length
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(position<k){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            position++;
        }
        // baaki recursion sambhal lega
        if(curr!=NULL){
            ListNode* recursionHead = reverseKGroup(curr,k);
            head->next = recursionHead;
        }
        return prev;
    }
};