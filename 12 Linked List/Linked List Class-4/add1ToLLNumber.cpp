// gfg: Add 1 to a Linked List Number


class Solution
{
    public:
    Node* reverseList(Node* &head){
            Node* prev = NULL;
            Node* curr = head;
            while(curr!=NULL){
                Node* forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }
            return prev;
        }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        // step1: reverse list
        head = reverseList(head);
        // step2: add one
        // mujhe plus one krna hai, toh carry ko hi 1 manlia
        int carry = 1;
        Node* temp = head;
        while(temp!=NULL){
            int sum = carry + temp->data;
            // current node me 1 hi digit store hoga, double digit nhi ho skta
            int digit = sum%10;
            carry = sum/10;
            temp->data = digit;
            // move to next node
            // special case for last node only
            if(temp->next == NULL && carry!=0){
                Node* newNode = new Node(carry);
                temp->next = newNode;
                temp=newNode;
            }
            temp = temp->next;
        }
        // step3: reverse list
        head = reverseList(head);
        return head;
    }
};

