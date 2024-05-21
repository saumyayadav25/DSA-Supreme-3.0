#include<iostream>
using namespace std;
//2d array

int main(){
    //method-1
    int arr[3][3]={
        {10,20,100},
        {30,40,200},
        {50,60,300}
        };
    
    //method-2
    //int arr[3][2]={10,20,30,40,50,60};

    // int arr[3][2]={10,20}; //remaining values will be zero
    int rowSize=3;
    int colSize=3;
    //row-wise traversing
    cout<<"row wise"<<endl;
    for( int rowIndex=0; rowIndex<rowSize;rowIndex++){
        for(int colIndex=0; colIndex<colSize; colIndex++){
            cout<<arr[rowIndex][colIndex]<<" ";
        }
        cout<<endl;
    }

    //column-wise traversing
    //square matrix:
    cout<<"column wise"<<endl;
    for( int rowIndex=0; rowIndex<rowSize;rowIndex++){
        for(int colIndex=0; colIndex<colSize; colIndex++){
            cout<<arr[colIndex][rowIndex]<<" ";
        }
        cout<<endl;
    }
    //generalized
    for(int col=0; col<colSize;col++){
        for(int row=0; row<rowSize;row++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    //diagonal traversing: square matrix
    cout<<"diagonal"<<endl;
    // for( int rowIndex=0; rowIndex<rowSize;rowIndex++){
    //     for(int colIndex=0; colIndex<colSize; colIndex++){
    //         if(rowIndex==colIndex){
    //             cout<<arr[rowIndex][colIndex]<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<rowSize;i++){
        cout<<arr[i][i]<<" ";
    }
    return 0;
} 
