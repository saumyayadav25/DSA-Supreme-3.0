// gfg: Flatttening a Linked List

/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class Solution {
public:
	Node*merge(Node*a, Node*b){
		if(!a) return b;
		if(!b) return a;
		Node* ans = 0;
		if(a->data < b->data){
			ans = a;
			a->bottom = merge(a->bottom, b);
		}
		else{
			ans = b;
			b->bottom = merge(a, b->bottom);
		}
		return ans;
	}
    Node *flatten(Node *root)
    {
        if(!root) return 0;
		Node* mergedLL = merge(root, flatten(root->next));
		return mergedLL;
    }
};