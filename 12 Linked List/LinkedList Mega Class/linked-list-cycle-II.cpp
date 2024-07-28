// leetcode 142: Linked List Cycle II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(fast == slow) return fast;
        }
        return nullptr;
    }
    // slow-fast approach
    ListNode *detectCycle(ListNode *head) {
        // step-1: check if loop is there or not
        ListNode*fast = hasCycle(head);
        if(!fast) return nullptr;
        // fast is non-null means->cycle is there
        // find starting point of cycle
        ListNode*slow = head;
        // now move slow & fast ptr with 1x speed and return where they meet
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;   //starting point
    }
};


// BRUTE FORCE METHOD
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> m;
        ListNode* temp = head;
        while(temp!=NULL){
            if(m[temp]==true) return temp;
            else{
                m[temp]=true;
            }
            temp=temp->next;
        }
        return temp;
    }
};