// leetcode 236. Lowest Common Ancestor of a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL) return NULL;
        // if(root->val == p->val) return p; //value based comparison, in this question all values are unique but if all values are non-unique then used address based comparison
        if(root == p) return p; //address based comparison
        // if(root-> val == q->val) return q;
        if(root == q) return q;

        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        if(leftAns == NULL && rightAns == NULL) return NULL;
        else if(leftAns == NULL && rightAns != NULL) return rightAns;
        else if(leftAns != NULL && rightAns == NULL) return leftAns;
        else{
            // both leftAns and rightAns are non null
            return root;
        }
    }
};