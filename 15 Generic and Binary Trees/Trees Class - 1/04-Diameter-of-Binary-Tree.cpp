// leetcode 543. Diameter of Binary Tree

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
        if(root == NULL){
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int maxHeight = max(left,right);
        int totalHeight = maxHeight + 1;
        return totalHeight;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = getHeight(root->left) + getHeight(root->right);
        int maxDiamater = max(option1,max(option2,option3));
        return maxDiamater;
    }
};

// fast way: in assignment