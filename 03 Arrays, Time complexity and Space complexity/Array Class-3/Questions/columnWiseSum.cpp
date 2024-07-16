#include<iostream>
using namespace std;
//column-wise sum
void columnWiseSum(int arr[][4],int rowSize, int colSize){
    
    for(int j=0; j<colSize; j++){
        int sum=0;
        for( int i=0; i<rowSize;i++){
            sum=sum+arr[i][j];
        }
        cout<< sum << endl;
    }
}
int main(){
    int arr[3][4]={{10,20,30,10},
                    {40,80,80,20},
                    {20,40,60,30}};
    int rowSize=3;
    int colSize=4;
    columnWiseSum(arr,rowSize,colSize);
    return 0;
} 
