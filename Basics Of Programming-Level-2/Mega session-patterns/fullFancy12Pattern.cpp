#include<iostream>
using namespace std;
//Full Fancy 12 pattern
//1
//2*2
//3*3*3
//4*4*4*4
//5*5*5*5*5
//4*4*4*4
//3*3*3
//2*2
//1
void fancy12(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<2*i+1;j++){
            if(j%2==0){
                cout<<i+1;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}
void fullFancy12(int n){
    fancy12(n);
    n--;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*(n-i)-1;j++){
            if(j%2==0){
                cout<<n-i;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    
}
int main(){
    int n;
    cin>>n;
    fullFancy12(n);
    return 0;
}
