#include<iostream>
using namespace std;
void fullPyramid(int n){
    for(int row=0;row<n;row++){
        // spaces
        for(int col=0;col<n-row-1;col++){
            cout<<" ";
        }
        //stars
        for(int col=0; col<row+1;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    fullPyramid(n);
    return 0;
}
