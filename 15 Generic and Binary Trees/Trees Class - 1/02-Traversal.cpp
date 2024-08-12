#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }

};

Node* createTree(){
        // cout << "Enter the value for Node " << endl;
        int value;
        cin >> value;

        if(value == -1){
            return NULL;
        }
        else{
            // valid value
            Node* root = new Node(value);
            // 1 case done, left and right will be done by recursion
            // cout << "adding left child for " << value << endl;
            root->left = createTree();
            // cout << "adding right child for " << value << endl;
            root->right = createTree();
            return root;
        }
    }

void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // NLR
    // N
    cout << root-> data << " ";
    // L -> left subtree
    preOrderTraversal(root->left);
    // R -> right subtree
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    if(root == NULL) return;
    //LNR
    // L
    inOrderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL) return;
    // LRN
    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout << root->data <<" ";
}

void LevelOrderTraversal(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    // initial state maintain
    q.push(root);
    q.push(NULL);
    // logic-> steps A, B, C
    while(!q.empty()){
        // queue se nikalo
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            // current level complete hogya hai
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            // print karao
            cout<< front->data << " ";
            // bache khalo-> queue me insert
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
        
    }
}

int main(){
    Node* root;
    root = createTree();
    
    // LOT
    // 10 50 40 -1 -1 -1 30 20 -1 -1 -1
    LevelOrderTraversal(root);
    // cout << "printing root " << root->data << endl;
    return 0;
}