#include<iostream>
using namespace std;
//taking input
int main(){
    int arr[2][3];
    int rowSize=2;
    int colSize=3;
    for(int r=0;r<rowSize;r++){
        for(int c=0;c<colSize;c++){
            cout<<"enter the value for ("<< r <<", "<< c <<") : ";
            cin>>arr[r][c];
        }
    }
    for( int rowIndex=0; rowIndex<rowSize;rowIndex++){
        for(int colIndex=0; colIndex<colSize; colIndex++){
            cout<<arr[rowIndex][colIndex]<<" ";
        }
        cout<<endl;
    }
    return 0;
} 
