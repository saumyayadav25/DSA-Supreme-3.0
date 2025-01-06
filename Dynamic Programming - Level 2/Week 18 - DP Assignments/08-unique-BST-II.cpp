// leetcode 95. Unique Binary Search Trees II
// can be submitted without dp solution as well

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
    vector<TreeNode*> allPossibleBSTs(int start, int end){
        // base case
        if(start > end) return {0};
        if(start == end) return {new TreeNode(start)};
        vector<TreeNode*>ans;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left = allPossibleBSTs(start, i - 1);
            vector<TreeNode*> right = allPossibleBSTs(i + 1, end);
            for(int j = 0; j < left.size(); j++){
                for(int k = 0; k < right.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    // 3d dp
    map<pair<int, int>, vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleBSTsTD(int start, int end){
        // base case
        if(start > end) return {0};
        if(start == end) return {new TreeNode(start)};
        if(dp.find({start, end}) != dp.end()) return dp[{start, end}];
        vector<TreeNode*>ans;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left = allPossibleBSTs(start, i - 1);
            vector<TreeNode*> right = allPossibleBSTs(i + 1, end);
            for(int j = 0; j < left.size(); j++){
                for(int k = 0; k < right.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return dp[{start, end}] = ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        // return allPossibleBSTs(1, n);
        return allPossibleBSTsTD(1, n);
    }
};