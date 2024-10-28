// gfg->DIY
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
        

        // DELETE LOOP
        ListNode*prev = 0;
        while(slow!=fast){
            slow=slow->next;
            prev=fast;
            fast=fast->next;
        }
        prev->next = nullptr; //loop remove
        return slow;   //starting point
    }
};








//(self) gfg solution:
class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if(head==NULL) return;
        Node*slow = head;
        Node*fast = head;
        bool cycleExist = false;
        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast==slow){
                cycleExist = true;
                break;
            }
        }
        
        if(!cycleExist) return;
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        Node* slowMeetFastHere = slow;
        while(fast->next!=slowMeetFastHere){
            fast = fast->next;
        }
        fast->next = NULL;
    }
};
