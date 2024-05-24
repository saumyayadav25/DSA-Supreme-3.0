#include<iostream>
using namespace std;
//solid half diamond

int main(){
    int n=5;
    for(int i=0; i<2*n-1; i++){
        int cond=0;
        if(i<n){
            //growing phase of half diamond
            cond=i;
        }
        else{
            //shrinking phase of half diamond
            cond=n-(i%n)-2;
        }
        for(int j=0; j<=cond;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
