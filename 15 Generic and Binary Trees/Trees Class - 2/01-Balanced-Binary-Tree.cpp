// leetcode 110. Balanced Binary Tree

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
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        int ansHeight = max(lh,rh) + 1;
        return ansHeight;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        // 1case: current node par check laga rha hoon
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        int absDiff = abs(lh-rh);
        bool status = absDiff <= 1;
        // recursion
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        // tree is balanced then curr node is balanced and left subtree is balanced, right subtree is balanced
        if(status && leftAns && rightAns) return true;
        else return false;
    }
};

// fast way: in assignment