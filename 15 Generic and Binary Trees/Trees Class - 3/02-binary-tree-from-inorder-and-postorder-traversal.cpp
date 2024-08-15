// leetcode 106. Construct Binary Tree from Inorder and Postorder Traversal

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
    void createMapping(unordered_map<int,int>&valueToIndex, vector<int>inorder){
        for(int i = 0; i < inorder.size(); i++){
            int element = inorder[i];
            int index = i;
            valueToIndex[element] = index;
        }
    }

    TreeNode* constructTree(unordered_map<int,int>&valMap, vector<int>&postOrder, vector<int>&inorder, int &postIndex,int inorderStart, int inorderEnd, int size){
        // base case
        if(postIndex<0) return NULL;
        if(inorderStart>inorderEnd) return NULL;
        int element = postOrder[postIndex];
        postIndex--;
        TreeNode* root = new TreeNode(element);
        int index = valMap[element];
        // right call
        root->right = constructTree(valMap, postOrder, inorder, postIndex, index+1, inorderEnd, size);
        // left call
        root->left = constructTree(valMap,postOrder, inorder, postIndex, inorderStart,index-1,size);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size()-1;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int size = inorder.size();
        unordered_map<int,int> valMap;
        createMapping(valMap, inorder);
        TreeNode* root = constructTree(valMap, postorder,inorder, postIndex,inorderStart, inorderEnd,size);
        return root;
    }
};