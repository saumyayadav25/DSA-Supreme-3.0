// leetcode 543. Diameter of Binary Tree(Fast way)
// TC:O(N^2)->done in trees class - 1

// optimised: TC:O(N)
class Solution {
public:
    int d = 0;
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        // diameter
        int currDiameter = lh + rh;
        d = max(d,currDiameter);
        return max(lh,rh) + 1; 
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return d;
    }
};