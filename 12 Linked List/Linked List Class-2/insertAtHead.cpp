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
        // STEP 1: create node
        Node* newNode = new Node(value);
        // STEP 2: newNode->next ko head pe lagado
        newNode->next = head;
        // STEP 3: head->prev ko newNode pe lagado
        head->prev = newNode;
        // head update
        head = newNode;
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

void printReverse(Node* tail){
    Node* temp = tail;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(10,head,tail);
    print(head);
    insertAtHead(20,head,tail);
    print(head);
    insertAtHead(30,head,tail);
    print(head);
    printReverse(tail);

    return 0;
}