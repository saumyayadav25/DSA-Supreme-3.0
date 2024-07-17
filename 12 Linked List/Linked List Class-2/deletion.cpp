#include<iostream>
using namespace std;
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    //constructor
    Node(int value){
        data = value;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(int value, Node* &head, Node* &tail){
    //LL is empty
    if(head==NULL & tail==NULL){
        Node* newNode = new Node(value);
        head= newNode;
        tail = newNode;
    }
    else{
        // LL is not empty
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(int value, Node* &head, Node* &tail){
    if(head == NULL && tail == NULL){
        //LL is empty
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else{
        //LL is not empty
        Node* newNode = new Node(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int getLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAtPosition(int position, int value,Node* &head, Node* &tail){
    int len = getLength(head);
    if(position==1){
        insertAtHead(value,head,tail);
    }
    else if(position==len+1){
        insertAtTail(value,head,tail);
    }
    else{
        //insert in middle of LL
        Node* temp = head;
        for(int i =0 ; i<position-2;i++){
            temp = temp->next;
        }
        // create node
        Node* newNode = new Node(value);
        // forward pointer set
        Node* forward = temp->next;
        // pointers ko set krdo
        newNode->prev = temp;
        temp->next = newNode;
        forward->prev = newNode;
        newNode->next = forward;
    }
}

void print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteFromPosition(int position, Node* &head, Node* &tail){
    int len = getLength(head);
    // LL is empty
    if(head == NULL && tail == NULL){
        cout<<"no node to delete";
    }
    else if(head == tail){
        //single node
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else if(position==1){
        //delete Head node
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if(len == position){
        Node* temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else{
        //delete node other than head
        Node* backward = head;
        for(int i=0; i<position-2;i++){
            backward = backward->next;
        }
        Node* curr = backward->next;
        Node* forward = curr->next;

        // pointers change
        backward->next = forward;
        forward->prev = backward;
        // isolate curr
        curr->prev = NULL;
        curr->next = NULL;
        
        delete curr;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(10,head,tail);
    insertAtTail(20,head,tail);
    insertAtTail(30,head,tail);
    print(head);

    insertAtPosition(3,420,head,tail);
    print(head);

    deleteFromPosition(4,head,tail);
    print(head);
    return 0;
}