#include<iostream>
using namespace std;

// class Stack{
//     public:
//         int* arr;
//         int size;
//         int top;
//         Stack(int capacity){
//             arr = new int(capacity);
//             size = capacity;
//             top = -1;
//         }
//         void push(int val){
//             if(top == size-1) cout<<"Stack Overflow"<<endl;
//             else{
//                 top++;
//                 arr[top] = val;
//             }
//         }

//         void pop(){
//             if(top == -1) cout<<"Stack underflow"<<endl;
//             else{
//                 arr[top]=0;
//                 top--;
//             }
//         }

//         int getSize(){
//             return top+1;
//         }

//         bool isEmpty(){
//             if(top == -1) return true;
//             else return false;
//         }

//         int getTop(){
//             if(top == -1){
//                 cout<<"There is no element at top, as stack is empty";
//                 return -1;
//             }
//             else return arr[top];
//         }

//         void print(){
//             cout<<"Printing Stack: "<<endl;
//             for(int i=0; i<size;i++){
//                 cout<<arr[i]<<" ";
//             } cout<<endl;
//         }
// };


class Stack{
    public:
        int* arr;
        int size;
        int top1;
        int top2;
        Stack(int capacity){
            arr = new int[capacity];
            size = capacity;
            top1 = -1;
            top2 = size;
        }

        void push1(int value){
            // if space available then push, else stack overflow 
            if(top2 - top1 == 1) cout<<"Stack overflow";
            else{
                top1++;
                arr[top1]=value;
            }
        }

        void push2(int value){
            if(top2-top1 == 1) cout<<"Stack overflow";
            else{
                top2--;
                arr[top2]=value;
            }
        }

        void pop1(){
            // if element available then pop, else Stack underflow
            if(top1==-1) cout<<"Stack underflow";
            else{
                arr[top1]=0;
                top1--;
            }
        }

        void pop2(){
            if(top2 == size) cout<<"Stack underflow";
            else{
                arr[top2]=0;
                top2++;
            }
        }

        void print(){
            cout<<"Top 1: "<<top1<<endl;
            cout<<"Top 2: "<<top2<<endl;
            for(int i=0; i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};


int main(){
    Stack s(5);
    s.push1(10);
    s.print();
    s.push2(90);
    s.print();
    s.push2(80);
    s.print();
    s.push2(90);
    s.print();
    s.push2(80);
    s.print();
    s.pop1();
    s.print();
    s.push2(90);
    s.print();
    s.push1(80);
    s.print();
    return 0;
}