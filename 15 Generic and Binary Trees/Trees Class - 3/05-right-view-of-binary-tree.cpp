// gfg: Right view of binary tree

class Solution
{
    public:
    void solve(Node*root,int level, vector<int>&ans){
    if(root==NULL) return;
    if(level == ans.size()) ans.push_back(root->data);
    solve(root->right,level+1,ans);
    solve(root->left, level+1,ans);
    
}
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int>ans;
        solve(root,0,ans);
        return ans;
    }
};