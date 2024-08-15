// gfg: Tree Boundary Traversal

class Solution {
public:
    void leftBoundary(Node* root, vector<int>&ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return; //leaf node
        ans.push_back(root->data);
        if(root->left!=NULL) leftBoundary(root->left,ans);
        else leftBoundary(root->right,ans);
    }

    void leafBoundary(Node* root, vector<int>&ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) ans.push_back(root->data);
        leafBoundary(root->left,ans);
        leafBoundary(root->right,ans);
    }
    
    void rightBoundary(Node* root, vector<int>&ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return; //leaf node
        if(root->right!=NULL) rightBoundary(root->right,ans);
        else rightBoundary(root->left,ans);
        // store in reverse order
        ans.push_back(root->data);
    }

    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL) return ans;
        // A->root node
        ans.push_back(root->data);
        // B->left subtree->left boundary
        leftBoundary(root->left,ans);
        // C->left subtree->leaf boundary
        leafBoundary(root->left,ans);
        // D->right subtree->leaf boundary
        leafBoundary(root->right,ans);
        // E->right subtree->right boundary
        rightBoundary(root->right,ans);
        return ans;
    }
};
