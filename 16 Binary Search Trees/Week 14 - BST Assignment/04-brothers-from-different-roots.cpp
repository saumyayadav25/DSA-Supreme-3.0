// gfg: Brothers From Different Roots

class Solution{
public:
    int countPairs(Node* root1, Node* root2, int x){
        int ans = 0;
        stack<Node*>s1,s2;
        Node*a = root1;
        Node*b = root2;
        while(1){
            while(a){
                // inorder
                s1.push(a);
                a = a->left;
            }
            while(b){
                // reverse inorder
                s2.push(b);
                b = b->right;
            }
            if(s1.empty() || s2.empty()){
                break;
            }
            auto atop = s1.top();
            auto btop = s2.top();

            int sum = atop->data + btop->data;
            if(sum==x){
                ans++;
                s1.pop();
                s2.pop();
                a = atop->right;
                b = btop->left;
            }
            else if(sum<x){
                s1.pop();
                a = atop->right;
            }
            else{
                s2.pop();
                b = btop->left;
            }
        }
        return ans;
    }
};
