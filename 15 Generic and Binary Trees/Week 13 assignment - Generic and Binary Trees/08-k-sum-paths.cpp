// leetcode 437. Path Sum III

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
    int ans = 0;
    
    void pathFromOneRoot(TreeNode* root, long long sum){
        // preorder
        if(!root) return;
        if(sum == root->val){ //phli node ki sum ke equal agyi
            ans++;
        }
        pathFromOneRoot(root->left, sum-root->val);
        pathFromOneRoot(root->right, sum - root->val);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root){
            pathFromOneRoot(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
};