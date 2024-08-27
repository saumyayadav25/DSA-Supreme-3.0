// leetcode 100. Same Tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p && q){
            return(p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right,q->right);
        }
        return false;
    }
};


// leetcode 101. Symmetric Tree
class Solution {
public:
    bool isMirror(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p && q){
            return(p->val == q->val) && isSameTree(p->left, q->right) && isSameTree(p->right,q->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};