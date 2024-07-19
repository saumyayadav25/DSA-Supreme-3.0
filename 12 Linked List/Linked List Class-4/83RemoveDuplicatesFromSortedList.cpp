// leetcode 83: Remove Duplicates from Sorted List

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
    ListNode* deleteDuplicates(ListNode* head) {
        //1st case-> LL is empty
        if(head==NULL) return head;
        //2nd case-> single node in LL
        if(head->next == NULL) return head;
        // 3rd case-> more than 1 nodes present
        ListNode* prev = head;
        ListNode* temp = head->next;

        while(temp!=NULL){
            
            // check duplicate
            if(temp->val == prev->val){
                //duplicate found->delete
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
            else{
                prev=prev->next;
                temp=temp->next;
            }
            temp = prev->next;
        }
        return head;
    }
};