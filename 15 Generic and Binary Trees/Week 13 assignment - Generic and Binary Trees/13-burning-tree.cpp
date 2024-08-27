// gfg: Burning Tree

class Solution {
  public:
    Node* makeNodeToParentMappingAndFindTargetNode(Node*root, unordered_map<Node*,Node*>&parentMap,int target){
        queue<Node*>q;
        Node* targetNode = 0;
        q.push(root);
        parentMap[root] = 0;
        while(!q.empty()){
            Node* front = q.front(); q.pop();
            if (front->data == target) {
                targetNode = front;
            }
            if(front->left){
                q.push(front->left);
                parentMap[front->left] = front;
            }
            if(front->right){
                q.push(front->right);
                parentMap[front->right] = front;
            }
        }
        return targetNode;
    }

    int burnTheTree(Node* targetNode, unordered_map<Node*,Node*>&parentMap){
        unordered_map<Node*,bool> isBurnt;
        queue<Node*>q; //currently set on fire nodes
        int T = 0;
        q.push(targetNode);
        isBurnt[targetNode] = true;
        while(!q.empty()){
            int size = q.size();
            bool isFireSpreaded = false;
            for(int i = 0; i < size; i++){
                Node* front = q.front();
                q.pop();
                if(front->left && !isBurnt[front->left]){
                    q.push(front->left); //set on fire
                    isBurnt[front->left] = true;
                    isFireSpreaded = true; // time will be incremented iff fire spreads
                }
                if(front->right && !isBurnt[front->right]){
                    q.push(front->right); 
                    isBurnt[front->right] = true;
                    isFireSpreaded = true;
                }
                if(parentMap[front] && !isBurnt[parentMap[front]]){
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]] = true;
                    isFireSpreaded = true;
                }
            }
            if(isFireSpreaded) T++;
        }
        return T;
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*,Node*>parentMap; //node -> its parent pointers
        Node* targetNode = makeNodeToParentMappingAndFindTargetNode(root,parentMap,target);
        return burnTheTree(targetNode,parentMap);
    }
};

