// leetcode 783. Minimum Distance Between BST Nodes

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
public:
    void solve(TreeNode* root,int&ans,TreeNode*&prev){
        // inorder
        if(!root) return;
        // L
        solve(root->left,ans,prev);
        // N
        if(prev){
            ans = min(ans, root->val - prev->val);
        }
        // update the prev
        prev = root;
        // R
        solve(root->right,ans,prev);
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        int ans = INT_MAX; //minimum difference
        solve(root,ans,prev);
        return ans;
    }
};