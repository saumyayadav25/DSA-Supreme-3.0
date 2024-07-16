#include<iostream>
using namespace std;
void invertedFullPyramid(int n){
    for(int row=0;row<n;row++){
        // spaces
        for(int col=0;col<row;col++){
            cout<<" ";
        }
        //stars
        for(int col=0; col<n-row;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    invertedFullPyramid(n);
    return 0;
}
