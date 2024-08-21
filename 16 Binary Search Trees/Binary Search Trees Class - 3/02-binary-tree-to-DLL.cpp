// gfg: Binary Tree to DLL

// using inorder LNR
class Solution {
public:
    void solve(Node* root, Node*&head,Node*&tail){
        if(root==NULL) return;
        // L
        solve(root->left,head,tail);
        // assume that left mai LL bangyi hai
        // update head and tail, connect root node to left LL
        // N
        if(tail!=NULL){
            tail->right = root;
            root->left = tail;
            // tail update
            tail = root;
        }
        else{
            head = root;
            tail = root;
        }
        // R
        solve(root->right,head,tail);
    }
    Node* bToDLL(Node* root) {
        Node* head = NULL;
        Node* tail = NULL;
        solve(root,head,tail);
        return head;
    }
};






// Using RNL
class Solution {
public:
    void solve(Node* root, Node*&head){
        if(root==NULL) return;
        // RNL
        // R
        solve(root->right,head);
        // assume that right part ki LL bangyi hogi and head right par ki LL ki start node par hoga
        // N
        root->right = head;
        if(head!=NULL){
            head->left = root;
        }
        // N and R ki LL ban chuki hai
        // update head, root node pe lagado
        head = root;
        // left part pending now
        // L
        solve(root->left,head);
    }
    Node* bToDLL(Node* root) {
        Node* head = NULL;
        solve(root,head);
        return head;
    }
};