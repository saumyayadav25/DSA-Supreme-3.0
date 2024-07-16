#include<iostream>
using namespace std;

int main(){
    
    //square pattern
    //outer loop
    for(int row=0;row<4;row++){
        //inner loop
        for(int col=0;col<4;col++){
            cout<<"* ";
        }
        //after printing 4 starts, go to next line
        cout<<endl;
    }
    return 0;
}
