// leetcode 430: Flatten a Multilevel Doubly Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node*solve(Node*head){
        if(!head) return nullptr;
        auto it = head;
        auto tail = it;  //for tracking tail node
        while(it){
            if(it->child){
                auto childTail = solve(it->child);  //tail node
                // flatten
                auto temp = it->next;
                it->next=it->child;
                it->next->prev = it;
                childTail->next = temp;
                if(temp) temp->prev = childTail;
                it->child=nullptr;
            }
            tail = it;
            it = it->next;
        }
        return tail;
    }

    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};