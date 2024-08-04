#include<iostream>
using namespace std;

class Queue{
    private:
        int *arr;
        int n;
        int front;
        int rear;
    public:
        Queue(int size){
            arr = new int[size];
            n = size;
            front = -1;
            rear = -1;
        }

        // TC: O(1)
        void push(int val){
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

        void pop(){
            // underflow
            if(front == -1 && rear == -1) cout << "Underflow"<<endl;
            // single element
            else if(front == rear){
                // arr[rear]=-1;   //optional
                front = -1;
                rear=-1;
            }
            // normal flow
            else{
                // arr[front]=-1;    //optional
                front++;
            }
        }

        int getFront(){
            if(front == -1) cout<<"Queue is empty";
            else return arr[front];
        }

        int getRear(){
            // HW
            if(rear == -1) cout<<"Queue is empty";
            else return arr[rear];
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
};

int main(){
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.getSize()<<endl;

    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    q.push(50);
    cout<<q.isEmpty()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.getSize()<<endl;
    return 0;
}