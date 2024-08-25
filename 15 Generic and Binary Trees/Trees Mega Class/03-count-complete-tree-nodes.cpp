// leetcode 222. Count Complete Tree Nodes

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
    // O(logn)
    int findLeftHeight(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->left;
        }
        return count;
    }
    // O(logn)
    int findRightHeight(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->right;
        }
        return count;
    }

public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if(lh == rh) return (1 << lh) - 1; //2^height - 1
        // if(lh!=rh)-> ans will be 1 + (...left ans) + (...right ans)
        int lans = countNodes(root->left);
        int rans = countNodes(root->right);
        return 1 + lans + rans;
    }
};