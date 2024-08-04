#include<iostream>
using namespace std;

class Deque{
    private:
        int *arr;
        int n;
        int front;
        int rear;
    public:
        Deque(int size){
            this->n = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        // TC: O(1)
        void pushFront(int val){
            // no space left in front
            if(front == 0) cout<<"Overflow"<<endl;
            // first element
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[front] = val;
            }
            // normal flow
            else{
                front--;
                arr[front] = val;
            }
        }

        void pushBack(int val){
            // overflow
            if(rear == n-1) cout << "Overflow"<<endl;
            // first element insert
            else if(front == -1 && rear == -1){
                rear++;
                front++;
                arr[rear] = val;
            }
            // normal flow
            else{
                rear++;
                arr[rear] = val;
            }
        }

        void popfront(){
            // underflow
            if(front == -1 && rear == -1) cout << "Underflow"<<endl;
            // single element
            else if(front == rear){
                arr[rear]=-1;   //optional
                front = -1;
                rear=-1;
            }
            // normal flow
            else{
                arr[front]=-1;    //optional
                front++;
            }
        }

        void popBack(){
            // no element present
            if(front == -1 && rear == -1) cout<<"Underflow"<<endl;
            // single element
            else if(front == rear){
                arr[rear] = -1;
                front = -1;
                rear = -1;
            }
            // normal flow
            else{
                arr[rear] = -1;  //optional
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
    Deque dq(5);

    dq.pushFront(10);
    dq.print();
    dq.pushFront(20);
    dq.print();
    dq.pushBack(15);
    dq.print();
    dq.pushBack(35);
    dq.print();
    dq.pushFront(100);
    dq.print();

    dq.popBack();
    dq.print();
    dq.popfront();
    dq.print();
    dq.popfront();
    dq.print();
    dq.popfront();
    return 0;
}