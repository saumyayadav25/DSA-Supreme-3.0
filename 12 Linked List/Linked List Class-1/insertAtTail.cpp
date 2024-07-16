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

//returns head of the updated list
Node* insertAtTail(int value, Node* &head, Node* &tail){
    if(head==NULL && tail==NULL){
        //LL is empty
        //STEP 1: CREATE NODE
        Node* newNode = new Node(value);
        //STEP 2: HEAD ON THAT NODE
        head = newNode;
        //STEP 3: TAIL ON THAT NODE
        tail = newNode;
    }
        // LL is not empty
    else{
        // STEP 1: CREATE A NEW NODE
        Node* newNode = new Node(value);
        // STEP 2: TAIL NODE KO NEWNODE SE CONNECT KRO
        tail->next = newNode;
        // STEP 3: TAIL UPDATE KRDO
        tail = newNode;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    //jab tk mera temp NULL k equal nhi hai, tab ta node print kro
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp-> next;
        
    }
    cout<<"NULL"<<endl;
}

int main(){
    //LL is empty
    Node* head = NULL;
    Node* tail = NULL;

    head = insertAtTail(101, head, tail);
    print(head);
    head = insertAtTail(102,head,tail);
    print(head);
    head = insertAtTail(103,head,tail);
    print(head);
    return 0;
}