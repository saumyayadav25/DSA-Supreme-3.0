#include<iostream>
using namespace std;
//transpose of a matrix

//method-1: making new array
void transposeMatrix(int arr[][3], int rowSize, int colSize){
    int ans[100][100]={0};
    for( int i=0; i<rowSize; i++){
        for( int j=0; j<colSize;j++){
            ans[i][j]=arr[j][i];
        }
    }

    for( int i=0; i<rowSize;i++){
        for( int j=0; j<colSize;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

//method-2: without making new array
void transposeMatrix2(int arr[][3], int rowSize, int colSize){
    for( int i=0; i<rowSize; i++){
        for( int j=i; j<colSize;j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    for( int i=0; i<rowSize;i++){
        for( int j=0; j<colSize;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[3][3]={{10,11,12},
                    {20,21,22},
                    {30,31,32}};
    int rowSize=3;
    int colSize=3;
    transposeMatrix(arr, rowSize, colSize);
    cout<<endl;
    transposeMatrix2(arr, rowSize, colSize);
    return 0;
} 
