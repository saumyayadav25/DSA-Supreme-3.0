// gfg: Is Binary Tree Heap

class Solution {
  public:

    bool checkCompleteness(Node*root){
        queue<Node*>q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front==NULL){
                nullFound = true;
            }
            else{
                // front is a valid node
                if(nullFound){
                    // not a cbt
                    return false;
                }
                else{
                    // may be a cbt, continue processing
                q.push(front->left);
                q.push(front->right);
                }
                
            }
        }
        return true;
    }

    bool checkMaxProperty(Node*root){
        if(root==NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        bool leftAns = checkMaxProperty(root->left);
        bool rightAns = checkMaxProperty(root->right);

        bool option1 = true;
        if(root->left && root->data < root->left->data) option1 = false;
        bool option2 = true;
        if(root->right && root->data < root->right->data) option2 = false;
        bool currAns = option1 && option2;
        if(currAns && leftAns && rightAns) return true;
        else return false;
    }

    bool isHeap(struct Node* tree) {
        bool completeness = checkCompleteness(tree);
        bool maxProperty = checkMaxProperty(tree);
        if(completeness && maxProperty) return true;
        return false;
    }
};