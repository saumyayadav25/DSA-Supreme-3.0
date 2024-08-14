// leetcode 112. Path Sum

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
    bool solve(TreeNode* root, int target, int sum){
        if(root == NULL) return false;
        // ab root pakka non null hai
        sum = sum + root->val;
        if(root->left == NULL && root->right == NULL){
            // root is leaf node
            if(sum == target) return true;
            else return false;
        }
        bool leftAns = solve(root->left,target,sum);
        bool rightAns = solve(root->right,target,sum);
        
        // if(leftAns == false && rightAns == false) return false;
        // else if(leftAns == true && rightAns == false) return true;
        // else if(leftAns == false && rightAns == true) return true;
        // else return true; 
        return leftAns || rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root,targetSum,sum);
        return ans;
    }
};