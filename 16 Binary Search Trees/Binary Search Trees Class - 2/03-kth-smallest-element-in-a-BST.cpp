// leetcode 230. Kth Smallest Element in a BST

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

// RECURSIVELY
class Solution {
public:
    void solve(TreeNode* root, int k, int &count,TreeNode*&ans){
        if(root == NULL) return;
        // LNR
        solve(root->left,k,count,ans);
        count++;
        if(count == k) {
            ans = root;
            return;
        }
        solve(root->right, k, count,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode* ans = NULL;
        solve(root,k,count,ans);
        return ans->val;
    }
};



// USING INORDER
class Solution {
public:
    void storeInorder(TreeNode* root, vector<int>&inorder){
        if(root==NULL) return;
        // LNR
        storeInorder(root->left,inorder);
        inorder.push_back(root->val);
        storeInorder(root->right,inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        storeInorder(root,inorder);
        return inorder[k-1];
    }
};