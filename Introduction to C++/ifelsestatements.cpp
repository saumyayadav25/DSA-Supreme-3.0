#include<iostream>
using namespace std;
int main(){
    int marks=90;
    if(marks>=90){
        cout<<"A";
    }
    else if(marks>=80){
        cout<<"B";
    }
    else if(marks>=70){
        cout<<"C";
    }
    else if(marks>=50){
        cout<<"D";
    }
    else{
        cout<<"fail";
    }
    return 0;
}
