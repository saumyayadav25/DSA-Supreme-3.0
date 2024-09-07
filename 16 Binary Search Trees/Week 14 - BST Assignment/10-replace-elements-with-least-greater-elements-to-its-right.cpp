// gfg: Replace every element with the least greater element on its right

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val): data(val), left(0), right(0){};
        // Node(int val){
        //     this->data = val;
        //     left = NULL;
        //     right = NULL;
        // }
};

class Solution{
    public:
    Node* insert(Node*root, int val, int &succ){
        if(!root) return new Node(val);
        if(val>=root->data){
            root->right = insert(root->right,val,succ);
        }
        else{
            succ = root->data;
            root->left = insert(root->left, val,succ);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(arr.size(),-1);
        Node* root = 0;
        for(int i = arr.size() - 1; i >=0; i--){
            int succ = -1;
            root = insert(root,arr[i],succ);
            ans[i] = succ;
        }
        return ans;
    }
};