// leetcode 173. Binary Search Tree Iterator

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
    stack<TreeNode*>st; //using this stack, i am doing LNR(inorder traversal)
    void pushLeftNodes(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
    }
    
    int next() {
        auto top = st.top();
        st.pop();
        if(top->right){
            pushLeftNodes(top->right);
        }
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};



// using reverse inorder traversal
class BSTIterator {
    stack<TreeNode*>st; // using this stack, i am doing LNR(inorder traversal)
    stack<TreeNode*>revSt; // reverse inorder traversal
    void pushLeftNodes(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    void pushRightNodes(TreeNode* root){
        while(root){
            revSt.push(root);
            root = root->right;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
        pushRightNodes(root);
    }
    
    int next() {
        auto top = st.top();
        st.pop();
        if(top->right){
            pushLeftNodes(top->right);
        }
        return top->val;
    }
    int before() {
        auto top = revSt.top();
        revSt.pop();
        if(top->left){
            pushRightNodes(top->left);
        }
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    bool hasBefore() {
        return !revSt.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */