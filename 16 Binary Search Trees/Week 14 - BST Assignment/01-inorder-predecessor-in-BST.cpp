// Inorder Predecessor of Node in BST

/* This is the Node class definition
class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
*/

Node* findPredecessor(Node* root, Node* p) {
    Node* pred = 0;
    Node* curr = root;
    while(curr){
        if(curr->data < p->data){
            pred = curr;
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return pred;
}