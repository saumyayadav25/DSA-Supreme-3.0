// leetcode 104. Maximum Depth of Binary Tree

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
    int maxDepth(TreeNode* root) {
        // base case
        if(root == NULL) return 0;
        // LRN
        int leftSubTreeHeight = maxDepth(root->left);
        int rightSubTreeHeight = maxDepth(root->right);
        int maxHeight = max(leftSubTreeHeight, rightSubTreeHeight);
        int totalHeight = maxHeight + 1;
        return totalHeight;
    }
};