// leetcode 235. Lowest Common Ancestor of a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//Using BST property-> TC:O(logn)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        // case A: p and q are both on left side-> neglect right
        if(p->val < root->val && q->val < root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
            if(leftAns != NULL) return leftAns;
        }
        // case B: p and q are both on right side-> neglect left
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right, p,q);
            if(rightAns != NULL) return rightAns;
        }
        // case C: p in left subtree, q in right subtree
        // case D: p in right subtree, q in left subree
        return root;
    }
};


// using Binary Tree approach->TC:O(N)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right, p,q);
        // 4cases
        if(left==NULL && right == NULL) return NULL;
        else if(left!=NULL && right == NULL) return left;
        else if(left==NULL && right!=NULL) return right;
        else return root;
    }
};