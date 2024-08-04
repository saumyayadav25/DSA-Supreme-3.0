#include<iostream>
using namespace std;

class DeCircularQueue{
    public:
        int *arr;
        int n;
        int front;
        int rear;
        DeCircularQueue(int size){
            this->n = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void pushFront(int val){
            // 4 cases: overflow, first element, circular nature, normal flow
            if((front == 0 && rear == n-1) || (rear == front -1)){
                cout<<"overflow"<<endl;
            }
            // first element
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[front] = val;
            }
            // circular nature
            else if(front == 0 && rear != n-1){
                front = n-1;
                arr[front] = val;
            }
            // normal
            else{
                front--;
                arr[front] = val;
            }
        }

        void pushBack(int val){
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

        void popfront(){
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

        void popBack(){
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
            else if(rear == 0){
                arr[rear] = -1;
                rear= n-1;
            }
            // normal case
            else{
                arr[rear] = -1;
                rear--;
            }
        }

        int getSize(){
            // number of elements inside a queue
            if(front == -1 && rear == -1) return 0;
            else return rear - front + 1;
        }

        bool isEmpty(){
            if(front == -1 && rear == -1) return true;
            else return false;
        }

        void print(){
            for(int i = 0; i<n;i++){
                cout<<arr[i]<<" ";
            } cout<<endl;
        }
};

int main(){
    DeCircularQueue q(5);
    q.pushFront(10);
    q.print();
    q.pushFront(20);
    q.print();
    q.pushBack(30);
    q.print();
    q.pushBack(40);
    q.print();
    q.pushBack(50);
    q.print();
    q.pushFront(60);
    q.print();

    q.popfront();
    q.print();
    q.popfront();
    q.print();
    q.popfront();
    q.print();
    q.popBack();
    q.print();
    q.popfront();
    q.print();
    return 0;
}