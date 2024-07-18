// leetcode 234: Palindrome Linked List

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
    ListNode* getMiddle(ListNode* head, ListNode* &middleNodeKaPrev){
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast!=NULL){
            fast= fast->next;
            if(fast!=NULL){
                fast=fast->next;
                middleNodeKaPrev=slow;
                slow=slow->next;
            }
        }
        return slow;
    }
    ListNode* reverselist(ListNode* &prev, ListNode* &curr){
        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr= forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            // LL is empty
            return true;
        }
        if(head->next == NULL){
            //single node
            return true;
        }
        // travel till middle node and break the LL in 2 halves
        ListNode* firstHalfHead = head;
        ListNode* middleNodeKaPrev = NULL;
        ListNode* middleNode = getMiddle(head,middleNodeKaPrev);
        // break
        middleNodeKaPrev ->next = NULL;
        // reverse the second half
        ListNode* prev=NULL;
        ListNode* curr=middleNode;
        ListNode* secondHalfHead = reverselist(prev,curr);
        // compare both the halves if they are equal
        // even length wale case me dono part ki length equal hogi
        // odd length wale case me second half ki length badi hogi by 1
        // that's why comparison firstHalf ke according krenge
        ListNode* tempHead1 = firstHalfHead;
        ListNode* tempHead2 = secondHalfHead;
        while(tempHead1!=NULL){
            if(tempHead1->val != tempHead2->val){
                return false;
            }
            else{
                //data equal hai toh aage wali node check kro
                tempHead1= tempHead1->next;
                tempHead2= tempHead2->next;
            }
        }

        return true;
    }
};