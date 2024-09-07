// gfg: Inorder Successor in BST

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* succ = 0;
        Node* curr = root;
        while(curr){
            if(curr->data > x->data){
                succ = curr;
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        return succ;
    }
};