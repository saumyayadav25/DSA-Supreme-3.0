// gfg: Left view of binary tree

void solve(Node*root,int level, vector<int>&ans){
    if(root==NULL) return;
    if(level == ans.size()) ans.push_back(root->data);
    solve(root->left, level+1,ans);
    solve(root->right,level+1,ans);
}

vector<int> leftView(Node *root)
{
    vector<int>ans;
    solve(root,0,ans);
    return ans;
}