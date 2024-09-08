// leetcode 99. Recover Binary Search Tree

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

class Solution {
    TreeNode* fv = 0, *sv = 0, *prev = 0;
public:
    void solve(TreeNode*curr){
        if(!curr) return;
        // L
        solve(curr->left);
        // N
        // store and compute
        if(prev && curr->val < prev->val){
            // property is violated
            if(!fv) fv = prev;
            sv = curr;
        }
        prev = curr;
        // R
        solve(curr->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        if(fv && sv) swap(fv->val,sv->val);
    }
};