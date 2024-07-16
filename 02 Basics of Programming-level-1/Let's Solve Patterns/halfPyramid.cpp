#include<iostream>
using namespace std;

int main(){
    //half pyramid
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    //outer loop
    for(int row=0;row<n;row++){
        //inner loop
        for(int col=0;col<row+1;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
