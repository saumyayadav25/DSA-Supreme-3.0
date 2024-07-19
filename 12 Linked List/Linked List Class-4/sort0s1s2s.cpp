// gfg: sort 0s, 1s and 2s in LL

class Solution
{
    public:
    void insertAtTail(Node* toMove, Node* &head, Node* &tail){
        // LL is empty
        if(head == NULL && tail == NULL){
            head = toMove;
            tail = toMove;
        }
        else{
            tail->next = toMove;
            tail = toMove;
        }
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zeroHead = NULL;
        Node* zeroTail = NULL;

        Node* oneHead = NULL;
        Node* oneTail = NULL;
        
        Node* twoHead = NULL;
        Node* twoTail = NULL;

        Node* temp = head;
        while(temp != NULL){
            // create toMove node
            Node* toMove = temp;
            temp = temp->next;
            // isolate toMove
            toMove->next = NULL;
            if(toMove->data == 0){
                insertAtTail(toMove,zeroHead,zeroTail);
            }
            else if(toMove->data == 1){
                insertAtTail(toMove,oneHead,oneTail);
            }
            else if(toMove->data == 2){
                insertAtTail(toMove,twoHead,twoTail);
            }
        }
        // teeno LL ready hai->merge
        // empty wali possibility bhoolna mat
        if(zeroHead != NULL){
            if(oneHead != NULL){
                zeroTail->next = oneHead;
                // merge with 2 wali list
                oneTail->next = twoHead;
            }
            else{
                // one list is empty
                zeroTail->next = twoHead;
            }
            return zeroHead;
        }
        else{
            // zero list is empty
            if(oneHead != NULL){
                oneTail->next = twoHead;
                return oneHead;
            }
            else{
                return twoHead;
            }
        }

    }
};

