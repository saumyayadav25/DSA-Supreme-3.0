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
    //LL is empty-> Head and Tail both point at NULL
    // it means we are creating first node of Ll
    if(head == NULL && tail == NULL){
        // STEP 1: CREATE A NEW NODE
        Node* newNode = new Node(value);
        // STEP 2: HEAD KO NODE PAR LAGADO
        head = newNode;
        //STEP 3: TAIL KO NEW NODE PE LAGADO
        tail = newNode;
    }
    //LL is not empty
    else{
        // STEP 1: CREATE A NEW NODE
        Node* newNode = new Node(value);
        // STEP 2: CONNECT THIS NEWNODE TO HEAD NODE
        newNode->next = head;
        // STEP 3: HEAD UPDATE KRDO
        head = newNode;
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
    Node* head = NULL;
    Node* tail = NULL;
    head = insertAtHead(10,head,tail);
    print(head);
    head = insertAtHead(20,head,tail);
    print(head);
    head = insertAtHead(30,head,tail);
    print(head);
    return 0;
}