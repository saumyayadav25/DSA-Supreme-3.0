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
    //assume-> valid position inputs given
    int length = getLength(head);
    if(position == 1){
        //insert at head
        head = insertAtHead(value,head,tail);
    }
    else if(position == length + 1){
        //insert at tail
        head = insertAtTail(value,head,tail);
    }
    else{
        //insert in between
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
    //jab tk mera temp NULL k equal nhi hai, tab ta node print kro
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp-> next;
        
    }
    cout<<"NULL"<<endl;
}

// searching: LINEAR SEARCH
bool searchLL(int target, Node*head){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == target) return true;
        temp = temp->next;
    }
    //poori LL traverse krli but target nhi mila
    return false;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    head = insertAtTail(101, head, tail);
    print(head);
    head = insertAtTail(102,head,tail);
    print(head);
    head = insertAtTail(103,head,tail);
    print(head);
    insertAtPosition(1,42,head,tail);
    print(head);
    insertAtPosition(5,57,head,tail);
    print(head);
    insertAtPosition(3,420,head,tail);
    print(head);
    cout<<searchLL(1103,head)<<endl;;
    return 0;
}