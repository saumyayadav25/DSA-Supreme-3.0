// leetcode 987. Vertical Order Traversal of a Binary Tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q; //Node, {row,col}
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>mp; //col->{row:[x,y,z...]}
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            TreeNode*&node = front.first;
            auto coordinate = front.second;
            int&row = coordinate.first;
            int&col = coordinate.second;
            mp[col][row].insert(node->val);
            if(node->left) q.push({node->left,{row+1,col-1}});
            if(node->right) q.push({node->right,{row+1,col+1}});
        }

        // store final vertical order into answer vector
        for(auto it:mp){
            auto&colMap = it.second;
            vector<int>vLine;
            for(auto colMapIt: colMap){
                auto&mset = colMapIt.second;
                vLine.insert(vLine.end(),mset.begin(),mset.end()); //vline ke end tk mset ko insert krdo
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};