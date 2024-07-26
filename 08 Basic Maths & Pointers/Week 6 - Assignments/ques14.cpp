#include<iostream>
using namespace std;

int main(){
    char st[]="ABCD";
    for(int i=0; st[i]!='\0';i++){
        cout<<st[i]<<" "<< *(st)+i<<" "<<*(i+st)<<" "<<i[st]<<endl ;
    }
    return 0;
}
