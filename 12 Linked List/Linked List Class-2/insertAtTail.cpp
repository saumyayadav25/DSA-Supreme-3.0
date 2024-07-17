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

void insertAtTail(int value, Node* &head, Node* &tail){
    if(head == NULL && tail == NULL){
        //LL is empty
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else{
        //LL is not empty
        // STEP 1: create node
        Node* newNode = new Node(value);
        // STEP 2: tail->next ko newNode pe lagado
        tail->next = newNode;
        // STEP 3: newNode->prev ko tail pe lagado
        newNode->prev = tail;
        // tail update
        tail = newNode;
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
    insertAtTail(10,head,tail);
    insertAtTail(20,head,tail);
    insertAtTail(30,head,tail);
    print(head);
    return 0;
}