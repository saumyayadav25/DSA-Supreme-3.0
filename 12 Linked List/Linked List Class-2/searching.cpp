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

bool searchInDLL(Node* &head, int target){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==target){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
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
    cout<<searchInDLL(head,30);
    return 0;
}