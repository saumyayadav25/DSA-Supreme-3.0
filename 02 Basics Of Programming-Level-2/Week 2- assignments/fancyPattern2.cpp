#include<iostream>
#include<assert.h>
using namespace std;
/*
1
2*3
4*5*6
7*8*9*10
7*8*9*10
4*5*6
2*3
1
*/
int main(){
    int n=4;
    int c=1;
    //growing phase
    for( int i=0; i<n; i++){
        for(int j=0; j<=i;j++){
            cout<<c;
            c++;
            if(j<i){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    int start=c-n;
    //shrinking phase
    for(int i=0; i<n;i++){
        int k=start;
        for(int j=0; j<=n-i-1;j++){
            cout<<k;
            k++;
            if(j<n-i-1){
                cout<<"*";
            }
        }
        start= start-(n-i-1);
        cout<<endl;
    }
    return 0;
}
