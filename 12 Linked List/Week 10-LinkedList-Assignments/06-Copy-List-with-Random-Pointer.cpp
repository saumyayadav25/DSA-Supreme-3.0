// leetcode 138: Copy List with Random Pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// TC:O(N), SC: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return 0;

        // Step 1: Clone A->A'
        Node*it = head; //iteratre over old head
        while(it){
            Node*clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }

        // Step 2: Assign random links of A' with the help of old Node A
        it = head;
        while(it){
            Node*clonedNode = it->next;
            clonedNode->random = it->random? it->random->next : nullptr;
            it = it->next->next;
        }

        // Step 3: Detach A' from A
        it = head;
        Node*clonedHead = it->next;
        while(it){
            Node*clonedNode= it->next;
            it->next = it->next->next;
            if(clonedNode->next){
                clonedNode->next = clonedNode->next->next;
            }
            it=it->next;
        }
        return clonedHead;
    }
};



// TC: O(N) , SC: O(n)
class Solution {
public:
    Node* helper(Node* head, unordered_map<Node*, Node*>&mp){
        if(head==0) return 0;
        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = helper(head->next, mp);
        
        // random links
        if(head->random){
            newHead->random = mp[head->random];
        }
        
        return newHead;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;  //old node->new node mapping
        return helper(head,mp);
    }
};