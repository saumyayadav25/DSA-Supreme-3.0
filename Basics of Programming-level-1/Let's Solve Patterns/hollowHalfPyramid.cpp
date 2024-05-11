#include<iostream>
using namespace std;

int main(){
    //hollow half pyramid
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    //method-1
    //outer loop
    for(int row=0;row<n;row++){
        //inner loop
        int totalColumns=row+1;
        for(int col=0;col<totalColumns;col++){
            if(row==0 || row==1 || row==n-1){
                cout<<"* ";
            }
            else{
                //middle rows
                if(col==0 || col==totalColumns-1){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }
    //method-2
    for(int row=0;row<n;row++){
        int totalColumns=row+1;
        for(int col=0;col<totalColumns;col++){
            if (row==0 || row==n-1 || col==0 || row==col){
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
