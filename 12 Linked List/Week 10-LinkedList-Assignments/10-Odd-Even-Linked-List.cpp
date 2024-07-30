// leetcode 328: Odd Even Linked List

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || head->next==0) return head;
        ListNode* h1 = head, *h2 = head->next;     //h1->odd indexed list, h2->even list
        ListNode* evenHead = h2;
        while(h2 && h2->next){
            h1->next = h2->next;
            h2->next = h2->next->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        // the two independent prepared list has been re-grouped
        h1->next =evenHead;
        return head;
    }
};