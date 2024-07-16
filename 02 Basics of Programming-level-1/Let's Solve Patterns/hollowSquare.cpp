#include<iostream>
using namespace std;

int main(){
    //hollow square
    int side;
    cout<<"enter side of square:"<<endl;
    cin>>side;
    //outer loop
    for(int row=0;row<side;row++){
        //inner loop
        for(int col=0; col<side;col++){
            //first and last row
            if(row==0 || row==side-1){
                cout<<"* ";
            }
            else{
                if(col==0 || col==side-1){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
