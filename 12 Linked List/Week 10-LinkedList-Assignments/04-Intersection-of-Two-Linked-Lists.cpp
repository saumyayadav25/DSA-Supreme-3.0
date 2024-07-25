// GFG: Intersection of Two Linked Lists

/* structure of list node:
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
*/

class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int, int> map;
        Node* curr = head2;
        // Hash L2 items
        while (curr) {
            map[curr->data]++;
            curr = curr->next;
        }

        Node* IL = NULL; // Intersection list head
        Node* it = NULL; // Intersection list iterator
        curr = head1;

        while (curr) {
            if (map.find(curr->data) != map.end() && map[curr->data] > 0) {
                // Node value found in L2 and count is greater than 0
                if (IL == NULL) {
                    IL = new Node(curr->data);
                    it = IL;
                } else {
                    it->next = new Node(curr->data); 
                    it = it->next;
                }
                map[curr->data]--;
            }
            curr = curr->next;
        }
        return IL;
    }
};
