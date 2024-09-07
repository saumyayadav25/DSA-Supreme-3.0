// gfg: Median of BST

// morris traversal
int findNodeCount(Node* root) {
    int count = 0;
    Node*curr = root;
    while(curr){
        // left node is NULL, then visit it and go right
        if(curr->left == nullptr){
            count++;
            curr=curr->right; //upar move kr gaye
        }
        // left node is NOT NULL
        else{
            // find inorder predecessor
            Node* pred = curr->left;
            while(pred->right!=curr && pred->right){
                pred = pred->right;
            }
            // if pred right node is NULL, then go left after establishing link from pred to curr;
            if(pred->right == nullptr){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                // right node is NOT NULL, left is already visited, go right after visiting curr node,while removing the link
                pred->right = nullptr;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

// morris traversal
float findMedianFunc(Node* root, int n) {
    int i = 0;
    int odd1 = (n+1)/2, odd1Val = -1;
    int even1 = n/2, even1Val = -1;
    int even2 = (n/2) + 1, even2Val = -1;
    Node*curr = root;
    while(curr){
        // left node is NULL, then visit it and go right
        if(curr->left == nullptr){
            i++;
            if(i == odd1) odd1Val = curr->data;
            if(i == even1) even1Val = curr->data;
            if(i == even2) even2Val = curr->data;
            curr=curr->right; //upar move kr gaye
        }
        // left node is NOT NULL
        else{
            // find inorder predecessor
            Node* pred = curr->left;
            while(pred->right!=curr && pred->right){
                pred = pred->right;
            }
            // if pred right node is NULL, then go left after establishing link from pred to curr;
            if(pred->right == nullptr){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                // right node is NOT NULL, left is already visited, go right after visiting curr node,while removing the link
                pred->right = nullptr;
                i++;
                if(i == odd1) odd1Val = curr->data;
                if(i == even1) even1Val = curr->data;
                if(i == even2) even2Val = curr->data;
                curr = curr->right;
            }
        }
    }
    float median = 0.0;
    if((n&1)==0) {
        // even
        median = (even1Val + even2Val) / 2.0;
    }
    else{
        // odd
        median = odd1Val;
    }
    return median;
}

float findMedian(struct Node *root){
    int n = findNodeCount(root);
    return findMedianFunc(root,n);
}
