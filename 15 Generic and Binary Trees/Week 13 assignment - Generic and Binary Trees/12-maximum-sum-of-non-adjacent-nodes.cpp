// gfg: Maximum sum of Non-adjacent nodes

class Solution{
  public:
    pair<int,int> getMaxSum_helper(Node*root){
        if(!root) return {0,0};
        auto left = getMaxSum_helper(root->left);
        auto right = getMaxSum_helper(root->right);
        // sum including the node
        int a = root->data + left.second + right.second;
        // sum excluding the node
        int b = max(left.first,left.second) + max(right.first,right.second);
        return {a,b};
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        auto ans = getMaxSum_helper(root);
        return max(ans.first,ans.second);
    }
};