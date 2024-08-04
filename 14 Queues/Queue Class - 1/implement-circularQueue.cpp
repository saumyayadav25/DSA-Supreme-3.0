#include<iostream>
using namespace std;

class CircularQueue{
    public:
        int *arr;
        int n;
        int front;
        int rear;
        CircularQueue(int size){
            arr = new int[size];
            this->n = size;
            front = -1;
            rear = -1;
        }

        void push(int val){
            // 4 cases: overflow, first element, circular nature, normal flow
            if((front == 0 && rear == n-1) || (rear == front -1)){
                cout<<"overflow"<<endl;
            }
            // first element
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[rear] = val;
            }
            // circular nature
            else if(rear == n-1 && front!=0){
                rear = 0;
                arr[rear] = val;
            }
            // normal
            else{
                rear++;
                arr[rear] = val;
            }
        }

        void pop(){
            // 4cases: underflow, single element, circular nature, normal flow
            if(front == -1 && rear == -1){
                cout<<"Underflow"<<endl;
            }
            // single element
            else if(front==rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            // circular nature
            else if(front == n-1){
                arr[front] = -1;
                front = 0;
            }
            // normal case
            else{
                arr[front] = -1;
                front++;
            }
        }

        int getFront(){
            if(front == -1){
                cout<<"Queue is empty";
            }
            else{
                return arr[front];
            }
        }

        int getRear(){
            // HW
            if(rear == -1) cout<<"Queue is empty";
            else return arr[rear];
        }

        int getSize(){
            if(front == -1 && rear == -1){
                return 0;
            }
            // normal
            else if(rear >= front) return rear-front+1;
            // circular case
            else return n-front+rear+1;
        }

        bool isEmpty(){
            if(front == -1 && rear==-1) return true;
            else return false;
        }
        void print(){
            for(int i = 0; i<n;i++){
                cout<<arr[i]<<" ";
            } cout<<endl;
        }
};

int main(){
    CircularQueue q(5);
    q.push(10);
    q.print();
    q.push(20);
    q.print();
    q.push(30);
    q.print();
    q.push(40);
    q.print();
    q.push(50);
    q.print();
    q.push(60);
    q.print();

    q.pop();
    q.pop();
    q.print();

    q.push(100);
    q.print();

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    return 0;
}