#include<iostream>
using namespace std;

void invertedHollowPyramid(int n){
    for(int row=0;row<n;row++){
        // spaces
        for(int col=0;col<row;col++){
            cout<<" ";
        }
        //stars
        for(int col=0; col<n-row;col++){
            if(row==0||row==n-1||col==0||col==n-row-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    invertedHollowPyramid(n);
    return 0;
}
