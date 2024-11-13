// lc 160. Intersection of Two Linked Lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*a = headA;
        ListNode*b = headB;
        while(a->next && b->next){
            if(a == b){
                return a;
            }
            a = a->next;
            b = b->next;
        }
        if(a->next == 0 && b->next == 0 && a!=b){
            return NULL;
        }
        if(a->next == NULL){
            // B linked list is larger or equal-> find out how much bigger it is
            int blen = 0;
            while(b->next){
                blen++;
                b = b->next;
            }
            while(blen--){
                headB = headB->next;
            }
        }
        else{
            // A linked list is larger-> find out how much bigger it is
            int alen = 0;
            while(a->next){
                alen++;
                a = a->next;
            }
            while(alen--){
                headA = headA->next;
            }
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};