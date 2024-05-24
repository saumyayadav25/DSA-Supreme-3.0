#include<iostream>
using namespace std;
//numeric hollow half pyramid

int main(){
    int n=5;
    for(int i=0; i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || i== n-1 || j==i){
                cout<<j+1;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

