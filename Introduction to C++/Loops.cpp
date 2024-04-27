#include<iostream>
using namespace std;
int main(){
    cout<<"FOR LOOP"<<endl;
    for(int count=1;count<=10;count++){
        cout<<"saumya"<<endl;
    }
    cout<<"BREAK KEYWORD"<<endl;
    for(int i=1;i<=10;i++){
        if(i==5){
            break;
        }
        cout<<i<<endl;
    }

    cout<<"CONTINUE KEYWORD"<<endl;
    for(int i=1;i<=10;i++){
        if(i==5){
            continue;
        }
        cout<< i<<" "<<endl;
    }

    cout<<"WHILE LOOP"<<endl;
    int i=1;
    while(i<=5){
        cout<<i<<endl;
        i=i+1;
    }

    //reverse counting 100 to 0
    for(int c=100; c>=0;c--){
        cout<<c<<" ";
    }

    // //alphabets A to Z
    // for(char ch='A';ch<='Z';ch++){
    //     cout<<ch;
    // }
    // //alphabets in lowercase
    // for(char ch='a';ch<='z';ch++){
    //     cout<<ch;
    // }

    cout<<"DO WHILE LOOP"<<endl;
    int d=1;
    do{
        //logic
        cout<<d<<" "<<endl;
        //updation
        d++;
    } while(d<=5);
    return 0;
}
