// leetcode 1382. Balance a Binar Search Tree

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
    void inorder(TreeNode*root, vector<int>&in){
        if(!root) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }

    TreeNode* buildTree(vector<int>&in, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end) >>1;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = buildTree(in,start,mid-1);
        root->right = buildTree(in,mid+1,end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in);

        // build balanced BST using inorder traversal
        return buildTree(in,0,in.size()-1);
    }
};