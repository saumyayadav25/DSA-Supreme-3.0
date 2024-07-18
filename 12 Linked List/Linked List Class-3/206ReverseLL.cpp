// leetcode 206: Reverse Linked List

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


// using recursion
class Solution {
public:
    ListNode* reverseList(ListNode* &prev, ListNode* &curr){
        // base case
        if(curr== NULL){
            //LL reverse ho chuki hai
            // reversed LL ke starting node pr prev wala pointer hai
            return prev;
        }
        // 1case
        ListNode* forward = curr->next;
        //current Node ko reverse direction me point krwaya
        curr->next=prev;
        // pointers ko ek step aage badhaya, baki recursion krdega
        prev= curr;
        curr=forward;
        return reverseList(prev,curr);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* newHead = reverseList(prev,curr);
        return newHead;
    }
};


// iterative way->better SC, same TC as of recursive method

class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev=curr;
            curr=forward;
        }
        //newhead  of LL->prev pointer
        return prev;
    }
};