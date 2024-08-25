// leetcode 968. Binary Tree Cameras

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
    int solve(TreeNode* root, int &cameras){
        if(!root) return 1; //null nodes are assumed to be covered.
        int left = solve(root->left,cameras);
        int right = solve(root->right,cameras);

        if(left == 0 || right == 0){
            // nodes are not covered
            cameras++;
            return 2; // my camera is installed 
        }
        if(left == 2 || right == 2){
            return 1; // already covered by my child
        }
        return 0; // not covered.
    }
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        int rootState = solve(root,cameras);
        if(rootState == 0) //not covered
            cameras++;
        return cameras;
    }
};