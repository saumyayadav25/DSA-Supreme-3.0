// leetcode 98. Validate Binary Search Tree

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
    bool validate(TreeNode* root, long long lb, long long ub){
        if(!root) return true;
        
        bool isCurrentNodeInRange = root->val > lb && root->val < ub;
        bool isLeftBST = true;
        bool isRightBST = true;
        if(isCurrentNodeInRange){
            isLeftBST = validate(root->left,lb,root->val);
            isRightBST = validate(root->right, root->val,ub);
        }

        return isCurrentNodeInRange && isLeftBST && isRightBST;
    }
public:
    bool isValidBST(TreeNode* root) {
        // long long lb = INT_MIN, ub = INT_MAX;
        long long lb = LONG_MIN, ub = LONG_MAX;
        return validate(root,lb,ub);
    }
};



// without storing in variable
class Solution {
    bool validate(TreeNode* root, long long lb, long long ub){
        if(!root) return true;
        return root->val > lb &&
            root->val < ub && validate(root->left,lb,root->val) &&
            validate(root->right, root->val,ub);
    }
public:
    bool isValidBST(TreeNode* root) {
        // long long lb = INT_MIN, ub = INT_MAX;
        long long lb = LONG_MIN, ub = LONG_MAX;
        return validate(root,lb,ub);
    }
};
