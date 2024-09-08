// leetcode 653. Two Sum IV- Input is a BST
// (done in BST class-2 using vectors)


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

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator it(root);

        int i = it.next(); //gives smallest element; L->R
        int j = it.before(); //gives largest element; R->L

        while(i<j){
            int sum = i + j;
            if(sum == k) return true;
            else if(sum < k) i = it.next(); // similar to start++
            else j = it.before(); // similar to end--
        }
        return false;
    }
};