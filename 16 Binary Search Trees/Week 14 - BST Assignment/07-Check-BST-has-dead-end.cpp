// gfg: Check Whether BST contains dead end

class Solution{
public:
    void fun(Node*root, unordered_map<int,bool>&visited, bool &ans){
        if(root==0) return;
        // visiting the node
        visited[root->data] = 1;
        if(root->left == 0 && root->right==0){
            // leaf node
            int xp1 = root->data + 1;
            int xm1 = root->data - 1 == 0 ? root->data : root->data - 1;
            if(visited.find(xp1) != visited.end() && visited.find(xm1) != visited.end()){
                ans = true;
                return;
            }
        }
        fun(root->left,visited,ans);
        fun(root->right, visited,ans);
    }
    bool isDeadEnd(Node *root){
        bool ans = false; //tells if there is Dead End or not
        unordered_map<int,bool>visited;
        fun(root,visited,ans);
        return ans;
    }
};