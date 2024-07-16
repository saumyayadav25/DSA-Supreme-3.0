#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        //constructor
        Node(int value){
            this->data = value;
            this->next = NULL;
        }
};

// returns head of the new LL after insertion
Node* insertAtHead(int value, Node* &head, Node* &tail){
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

//returns head of the updated list
Node* insertAtTail(int value, Node* &head, Node* &tail){
    if(head==NULL && tail==NULL){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

// to find number of nodes
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(int position, int value, Node* &head, Node* &tail){
    int length = getLength(head);
    if(position == 1){
        head = insertAtHead(value,head,tail);
    }
    else if(position == length + 1){
        head = insertAtTail(value,head,tail);
    }
    else{
        Node* temp = head;
        for(int i=0; i<position-2;i++){
            temp = temp->next;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp-> next;
        
    }
    cout<<"NULL"<<endl;
}

void deleteNodeFromLL(int position, Node* &head, Node* &tail){
    //CASE 1; if LL is empty-> we cannot delete
    if(head==NULL && tail==NULL) {
        cout<<"No node to delete"<<endl;
        return;
    }
    // CASE 2: single node in LL
    if(head == tail){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    else{
        //multiple nodes inside LL
        // 2 cases
        // 1st case: pos=1 delete
        if(position == 1){
            Node* temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            // 2nd case: any other node except first one
            Node* temp = head;
            for(int i=0; i<pos-2;i++){
                temp = temp->next;
            }
            Node* nodeToDelete = temp->next;
            Node* forward = nodeToDelete->next;
            temp->next = forward;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
        }
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    head = insertAtTail(101, head, tail);
    head = insertAtTail(102,head,tail);
    head = insertAtTail(103,head,tail);
    insertAtPosition(1,42,head,tail);
    insertAtPosition(5,57,head,tail);
    insertAtPosition(3,420,head,tail);
    print(head);
    deleteNodeFromLL(1,head,tail);
    print(head);
    deleteNodeFromLL(3,head,tail);
    print(head);
    deleteNodeFromLL(4,head,tail);
    print(head);
    return 0;
}
