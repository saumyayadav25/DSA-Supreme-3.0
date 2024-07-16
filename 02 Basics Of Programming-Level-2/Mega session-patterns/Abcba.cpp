#include<iostream>
using namespace std;
//ABCBA pattern
//A
//ABA
//ABCBA
//ABCDCBA
//ABCDEDCBA
void Abcba(int n){
    for(int i=0;i<n;i++){
        char ch='A'; //ASCII value 65 initialise
        for(int j=0;j<i+1;j++){
            cout<<ch;
            ch++;
        }
        ch--;
        while(ch>'A'){
            ch--;
            cout<<ch;
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    Abcba(n);
    return 0;
}
