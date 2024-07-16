#include<iostream>
using namespace std;

int main(){
    //hollow rectangle
    int length,width;
    cout<<"enter length:"<<endl;
    cin>>length;
    cout<<"enter width"<<endl;
    cin>>width;
    //outer loop
    for(int row=0; row<length; row++){
        //inner loop
        for(int col=0;col<width;col++){
            //first and last row
            if(row==0 || row==length-1){
                cout<<"*";
            }
            else{
                //middle rows
                if(col==0 || col==width-1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
