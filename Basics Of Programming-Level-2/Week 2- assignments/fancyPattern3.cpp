#include<iostream>
using namespace std;
/*
*
* 1 *
* 1 2 1 *
* 1 2 3 2 1 *
* 1 2 1 *
* 1 *
*
*/
int main(){
    int n=5;
    //growing phase
    cout<<"*"<<endl;
    for( int i=0; i<n; i++){
        int cond= (i<=n/2) ? 2*i : 2*(n-i-1);
        for(int j=0; j<=cond;j++){
            if(j==0){
                cout<<"*";
            }
            if(j<=cond/2){
                cout<<j+1;
            }
            else{
                cout<<cond-j+1;
            }
            if(j==2*i || j==2*(n-i-1)){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    cout<<"*";
    return 0;
}
