// leetcode 110. Balanced Binary Tree(Fast way)
// TC(O(N^2)): done in trees class - 2

// optimised: TC:O(N)
class Solution {
public:
    bool isbalanced = true;
    int getHeight(TreeNode* root){
        if(!root) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        // check for current node, is it balanced?
        if(isbalanced && abs(lh - rh) > 1) isbalanced = false; //if for any node isBalanced gets false, then no need to check further
        return max(lh,rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return isbalanced;
    }
};