// leetcode 141: Linked List Cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// method-2: small/fast approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(fast == slow) return true;
        }
        return false;
    }
};


// method-1
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> m;
        ListNode* temp = head;
        while(temp!=NULL){
            if(m[temp]==true){
                //phle se hi true hai->cycle present
                return true;
            }
            else{
                // phle se true nhi hai->mark visit
                m[temp]=true;
            }
            temp=temp->next;
        }
        // no cycle present, traversed whole LL
        return false;
    }
};