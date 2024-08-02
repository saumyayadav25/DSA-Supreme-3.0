#include<iostream>
using namespace std;

class Stack{
    public:
        int* arr;
        int size;
        int top;
        Stack(int capacity){
            arr = new int(capacity);
            size = capacity;
            top = -1;
        }
        void push(int val){
            // check stack overflow
            if(top == size-1){
                // stack is already full
                cout<<"Stack Overflow"<<endl;
            }
            else{
                //normal case->stack me khaali jagah hai
                top++;
                arr[top] = val;
            }
        }

        void pop(){
            // check if stack is empty->stack underflow
            if(top == -1){
                // stack is empty -> cannot pop
                cout<<"Stack underflow"<<endl;
            }
            else{
                arr[top]=0; //optional
                top--;
            }
        }

        int getSize(){
            return top+1;
        }

        bool isEmpty(){
            if(top == -1) return true;
            else return false;
        }

        int getTop(){
            if(top == -1){
                cout<<"There is no element at top, as stack is empty";
                return -1;
            }
            else return arr[top];
        }

        void print(){
            cout<<"Printing Stack: "<<endl;
            for(int i=0; i<size;i++){
                cout<<arr[i]<<" ";
            } cout<<endl;
        }
};

int main(){
    // creating a stack of initial size 5
    Stack s(5);
    s.push(10);
    s.print();
    s.push(20);
    s.print();
    s.push(30);
    s.print();
    s.push(40);
    s.print();
    s.push(50);
    s.print();
    s.push(60); //stack overflow
    s.print();

    cout<<s.getTop()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;

    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();  //stack underflow
    s.print();
    cout<<s.getSize()<<endl;
    return 0;
}