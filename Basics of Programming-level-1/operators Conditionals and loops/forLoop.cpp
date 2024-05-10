#include<iostream>
using namespace std;

int main(){
    //loops: for loop
    cout<<"counting from 1 to 5"<<endl;
    for(int i=1;i<=5;i=i+1){
        cout<<i<<endl;
    }
    cout<<"counting from 5 to 1"<<endl;
    int i=5;
    for(;i>=1;i=i-1){
        cout<<i<<endl;
    }
    for(;;){ //creates infinite loop
    if(i>10){
        break;
    }
    cout<<"hello"<<endl;
    i++;
    }
    for(int j=1;j<=10;j++);//{ //creates empty loop
        // cout<<(3*j); throws error: undeclared indetifier 'j'.
    //}
    for(int j=1;j<=10;j++);{ //creates empty loop
        cout<<"hello"<<endl;
    }
    return 0;
}
