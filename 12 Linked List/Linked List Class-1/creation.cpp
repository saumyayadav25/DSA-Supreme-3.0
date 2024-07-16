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

int main(){
    //stack
    // Node first;

    //dynamic memory
    Node* first = new Node();

    return 0;
}