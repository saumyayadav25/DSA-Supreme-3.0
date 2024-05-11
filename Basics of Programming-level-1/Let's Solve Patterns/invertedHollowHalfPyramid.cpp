#include<iostream>
using namespace std;

int main(){
    //inverted hollow half pyramid
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    //outer loop
    for(int row=0;row<n;row++){
        for(int col=0;col<n-row;col++){
            if (row==0 || row==n-1 || col==0 || row+col==n-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}
