#include<iostream>
using namespace std;

void hollowPyramid(int n){
    for(int row=0;row<n;row++){
        // spaces
        for(int col=0;col<n-row-1;col++){
            cout<<" ";
        }
        //stars
        for(int col=0; col<row+1;col++){
            if(row==0||col==0||col==row ){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}

void invertedHollowPyramid(int n){
    for(int row=0;row<n;row++){
        // spaces
        for(int col=0;col<row;col++){
            cout<<" ";
        }
        //stars
        for(int col=0; col<n-row;col++){
            if(row==n-1||col==0||col==n-row-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}

void hollowDiamond(int n){
    hollowPyramid(n);
    invertedHollowPyramid(n);
}
int main(){
    int n;
    cin>>n;
    hollowDiamond(n);
    return 0;
}
