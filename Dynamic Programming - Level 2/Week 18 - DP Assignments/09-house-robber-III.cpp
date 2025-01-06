// leetcode 337. House Robber III

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
// TC: exponential
    int solve(TreeNode* root){
        if(!root) return 0;
        int robThisHouse = 0, dontRobThisHouse = 0;
        // 1 case
        // rob current house
        robThisHouse += root->val;
        if(root->left) robThisHouse += solve(root->left->left) + solve(root->left->right);
        if(root->right) robThisHouse += solve(root->right->left) + solve(root->right->right);
        // dont rob current house
        dontRobThisHouse = solve(root->left) + solve(root->right);
        return max(robThisHouse, dontRobThisHouse);
    }
    
    // TC: O(N), SC: O(N)
    int solveTD(TreeNode* root, unordered_map<TreeNode*, int> &dp){
        if(!root) return 0;
        if(dp.find(root) != dp.end()) return dp[root];
        int robThisHouse = 0, dontRobThisHouse = 0;
        // 1 case
        // rob current house
        robThisHouse += root->val;
        if(root->left) robThisHouse += solveTD(root->left->left, dp) + solveTD(root->left->right, dp);
        if(root->right) robThisHouse += solveTD(root->right->left, dp) + solveTD(root->right->right, dp);
        // dont rob current house
        dontRobThisHouse = solveTD(root->left, dp) + solveTD(root->right, dp);
        return dp[root] = max(robThisHouse, dontRobThisHouse);
    }

    int rob(TreeNode* root) {
        // return solve(root);
        unordered_map<TreeNode*, int>dp;
        return solveTD(root, dp);
    }
};