#include<iostream>
using namespace std;
//numeric hollow inverted half pyramid

int main(){
    int n=5;
    for(int i=0; i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==0 || j==i+1 || j==n ){
                cout<<j;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
