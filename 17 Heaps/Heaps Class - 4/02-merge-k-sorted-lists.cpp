// leetcode 23. Merge K Sorted Lists

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

class compare{
    public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        // process first k elements
        // har list ka pehla element pq me insert krna hai
        int totalRows = lists.size();
        for(int row = 0; row < totalRows; row++){
            ListNode* temp = lists[row];
            if(temp != NULL){
                // if it is a valid node
                pq.push(temp);
            }
        }
        // main logic
        while(!pq.empty()){
            // front nikalo
            ListNode* front = pq.top();
            pq.pop();
            // insert in ans
            if(head==NULL && tail==NULL){
                // inserting first node in LL
                head = front;
                tail = front;
                // agar aage node hai toh pq me insert kro
                
            }
            else{
                // its not the first node, insert at tail
                tail->next = front;
                tail = front;
            }
            if(tail->next != NULL){
                pq.push(tail->next);
            }
        }
        return head;
    }
};